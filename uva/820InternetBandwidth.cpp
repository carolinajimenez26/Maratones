#include <bits/stdc++.h>
using namespace std;
#define inf numeric_limits<int>::max()
#define MAX 105
vector< int > G[MAX];//neighbor, cost of node n
int GW[MAX][MAX];
int p[MAX];
int nodes;
bool visitados[MAX];

void init(){
  memset(p,-1,sizeof p);
  memset(visitados,0,sizeof visitados);
}

bool dfs(int source, int target){//says if there are a path form source to target
  stack<int> st;
  visitados[source] = true;
  st.push(source);
  p[source] = -1;
  while(!st.empty()){
    int v = st.top();
    st.pop();
    if(v == target) return true; //there is a path
    for(int i = 0; i < G[v].size(); i++){
      int nv = G[v][i], nw = GW[v][nv];
      if(!visitados[nv] && nw > 0){
        visitados[nv] = true;
        st.push(nv);
        p[nv] = v; //the father of nv is v
      }
    }
  }
  return false;//there is no path
}

pair<int, vector<int> > minWeight(int target){
  int p1 = p[target];
  int w = inf;
  vector<int> path;
  path.push_back(target);
  while(p1 != -1){
    int nw = GW[p1][target];
    //cout << "p1 : " << p1 << " target : " << target << " nw : " << nw << endl;
    if(nw < w) w = nw;
    path.push_back(p1);
    target = p1;
    p1 = p[p1];
  }
  return make_pair(w,path);
}

void printpath(vector<int> &v){
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
}

void printgraph(){
    for(int i=0; i < nodes; i++){
      cout<<"Nodo "<<i<<": ";
      for(int j=0; j<G[i].size();j++){
        cout<<"("<<G[i][j]<<","<<GW[i][G[i][j]]<<") ";
      }
      cout<<endl;
    }
}

int FF(int source, int target){//Ford-Fulkerson
  int maxf = 0;
  while(dfs(source, target)){
    //cout<<"Encontre un camino"<<endl;
    pair<int, vector<int> > mw = minWeight(target);//get the min weight and the path
    //printgraph();
    //cout<<"Camino: "<<"Size(): "<<mw.second.size()<<endl;
    //printpath(mw.second);
    //cout<<"|"<<flag<<" min: "<<mw.first<<endl;

    maxf += mw.first;
    //cout << endl << mw.first << endl;
    for(int i = 0; i < mw.second.size() - 1; i++){
      GW[mw.second[i]][mw.second[i+1]] += mw.first;
      GW[mw.second[i+1]][mw.second[i]] -= mw.first;
    }
    init();
    //iter++;
  }
  return maxf;
}

int main(void){
  int  s, t, c, u, v, cost, cases = 1; //number of nodes, source, target and connections
  while(cin >> nodes && nodes != 0){
    cin >> s >> t >> c;
    memset(GW,-1,sizeof GW);
    init();
    for(int i = 0; i < c; i++){
      cin >> u >> v >> cost;
      if(GW[u][v]!=-1 || GW[v][u]!=-1 ){
        GW[u][v] += cost;
        GW[v][u] += cost;
      }else{
        G[u].push_back(v);
        G[v].push_back(u);
        GW[u][v] = cost;
        GW[v][u] = cost;
      }


    }
    cout << "Network " << cases++ << endl;
    cout << "The bandwidth is " << FF(s,t) << "." << endl<<endl;
  }
  return 0;
}
