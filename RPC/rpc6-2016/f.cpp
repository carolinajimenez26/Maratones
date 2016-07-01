#include <bits/stdc++.h>
using namespace std;
#define inf numeric_limits<int>::max()/2
#define MAX 2700
#define endl '\n'

unordered_map<string,int> CC;
int GW[MAX][MAX];
vector<int> G[MAX];
bool visitados[MAX];
int p[MAX];
int fct[MAX];
int smn[MAX];
int s,r,f,t;

void init(){
    int limit = s + 2*t + 1;
    for(int i=0; i<= limit ;i++)
        visitados[i] = false;
}

bool bfs(int source, int target){//says if there are a path form source to target
  queue<int> st;
  visitados[source] = true;
  st.push(source);
  p[source] = -1;
  while(!st.empty()){
    int v = st.front();
    st.pop();
    if(v == target) return true; //there is a path
    for(int i = 0; i < G[v].size(); i++){
      int nv = G[v][i];
      int nw = GW[v][nv];
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
    w = min(w,nw);
    path.push_back(p1);
    target = p1;
    p1 = p[p1];
  }
  return make_pair(w,path);
}

int FF(int source, int target){//Ford-Fulkerson
  int maxf = 0;
  while(bfs(source, target)){
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

string int2string(int x){
  stringstream ss;
  ss << x;
  string str = ss.str();
  return str;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  memset(GW,0,sizeof GW);
  memset(smn,0,sizeof smn);
  memset(fct,0,sizeof fct);
  int tt,cont=1, source, target;
  string  _c,_s,_f;
  cin>>s>>r>>f>>t;
  source =0;
  target = s + t*2 + 1 ;
  //supliers
  for(int i=0; i<r;i++){
    cin>>_s;
    if(!CC.count(_s)){
        CC[_s] = cont++;
    }
    G[source].push_back(CC[_s]);
    G[CC[_s]].push_back(source);
    GW[source][CC[_s]] = 1;
    GW[CC[_s]][source] = 1;
    smn[CC[_s]] = 1;
  }
  //factories
  for(int i=0; i<f;i++){
    cin>>_f;
    if(!CC.count(_f)){
        CC[_f] = cont++;
    }
    G[target].push_back(CC[_f]);
    G[CC[_f]].push_back(target);
    GW[target][CC[_f]] = 1;
    GW[CC[_f]][target] = 1;
    fct[CC[_f]] = 1;
  }
  string trp, trpp;
  for(int i=0;i<t;i++){
    cin>>tt;
    trp = "_f" + int2string(i);
    trpp = trp + "'";
    CC[trp]=cont++;
    CC[trpp]=cont++;
    G[CC[trp]].push_back(CC[trpp]);
    G[CC[trpp]].push_back(CC[trp]);
    GW[CC[trp]][CC[trpp]] = 1;
    GW[CC[trpp]][CC[trp]] = 1;
    for(int j=0;j<tt;j++){
      cin >> _c;
      if(smn[CC[_c]]){
        G[CC[_c]].push_back(CC[trp]);
        G[CC[trp]].push_back(CC[_c]);
        GW[CC[_c]][CC[trp]] = 1;
        GW[CC[trp]][CC[_c]] = 1;
      }else if(fct[CC[_c]]){
        G[CC[_c]].push_back(CC[trpp]);
        G[CC[trpp]].push_back(CC[_c]);
        GW[CC[_c]][CC[trpp]] = inf;
        GW[CC[trpp]][CC[_c]] = inf;
      }else{
        G[CC[_c]].push_back(CC[trp]);
        G[CC[trp]].push_back(CC[_c]);
        G[CC[_c]].push_back(CC[trpp]);
        G[CC[trpp]].push_back(CC[_c]);
        GW[CC[_c]][CC[trpp]] = 1;
        GW[CC[trpp]][CC[_c]] = 1;
        GW[CC[_c]][CC[trp]] = 1;
        GW[CC[trp]][CC[_c]] = 1;
      }
    }
  }

  cout << FF(source, target) << endl;


  return 0;
}
