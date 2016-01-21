// 1049 - One Way Roads
// http://lightoj.com/volume_showproblem.php?problem=1049
#include <bits/stdc++.h>
using namespace std;
vector< pair<int, int> > G[101]; // [to, weight]
vector<bool> visitados(101);
int positivos, negativos;

void init(int n){
  positivos = 0;
  negativos = 0;
  for(int i=1;i<=n;i++){
    G[i].clear();
    visitados[i] = false;
  }
}

void dfs(int source, int n){
  int cont = 0;
  stack<int > st;
  visitados[source] = true;
  st.push(source);
  while(!st.empty()){
    int v = st.top();
    st.pop();

    cont+=1;
    if(cont == 3) visitados[source] = false;

    for(int i=0;i<G[v].size();i++){
      int nv= G[v][i].first,nw = G[v][i].second;
      if(!visitados[nv]){
        visitados[nv] = true;
        st.push(nv);
        if(nw<0) negativos+= nw;
        else positivos+= nw;
        break; // asegurar seguir solo una direccion al inicio con source
      }
    }
  }
}

int main(){
  int t,n,ca=1,a,b,c;
  cin>>t;
  while(t--){
    cin>>n;
    init(n);
    for(int i=0;i<n;i++){
      cin>>a>>b>>c;
      G[a].push_back(make_pair(b,c));
      G[b].push_back(make_pair(a,(-1)*c));
    }
    dfs(1,n);
    cout<<"Case "<<ca++<<": "<<min(positivos,(-1)*negativos)<<endl;
  }
  return 0;
}
