#include <bits/stdc++.h>
using namespace std;
#define inf numeric_limits<int>::max()
#define MAX 105
vector< pair<int,int> > G[MAX];//neighbor, cost of node n
int p[MAX];
int f = inf;
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
      int nv = G[v][i].first, nw = G[v][i].second;
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
    int nw = G[p1][target].second;
    cout << "p1 : " << p1 << " target : " << target << " nw : " << nw << endl;
    if(nw < w) w = nw;
    path.push_back(p1);
    target = p1;
    p1 = p[p1];  
  }
  return make_pair(w,path);
}

int FF(int source, int target){//Ford-Fulkerson
  int maxf = 0;
  while(dfs(source, target)){
    pair<int, vector<int> > mw = minWeight(target);//get the min weight and the path
    maxf += mw.first;
    cout << endl << mw.first << endl;
    for(int i = 0; i < mw.second.size() - 1; i++){
      G[mw.second[i]][mw.second[i+1]].second += mw.first;
      G[mw.second[i+1]][mw.second[i]].second -= mw.first;
    }
    init();
  }
  return maxf;
}

int main(void){
  int nodes, s, t, c, u, v, cost, cases = 1; //number of nodes, source, target and connections
  while(cin >> nodes && nodes != 0){
    cin >> s >> t >> c;
    init();
    for(int i = 0; i < c; i++){
      cin >> u >> v >> cost;
      G[u].push_back(make_pair(v,cost));
      G[v].push_back(make_pair(u,cost));
    }
    cout << "Network " << cases++ << endl;
    cout << "The bandwidth is " << FF(s,t) << "." << endl;
  }
  return 0;
}
