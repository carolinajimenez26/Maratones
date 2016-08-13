#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define um unordered_map
#define MAX 3100
unordered_map<string,int> id;
vector<int> G[MAX];
bool vis[MAX];

void init(){
  for(int i=0; i<MAX; i++)
    G[i].clear();
}

int get_id(string &line) {
  if (id.count(line))
    return id[line];
  int ans = id.size();
  return id[line] = ans;
}

bool bfs(int s){
  queue<pair<int, int> > q;
  q.push(make_pair(s,0));
  vis[s] = 1;
  while(!q.empty()){
    int v = q.front().first;
    int d = q.front().second;
    q.pop();
    if(d > 5) return false;

    for(int i=0; i<G[v].size(); i++){
      int nv = G[v][i], nd = d + 1;
      if(!vis[nv]){
        q.push(make_pair(nv,nd));
        vis[nv] = true;
      }
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t, n;
  string a,b;
  cin>>t;
  while(t--){
    memset(vis,0,sizeof vis);
    init();
    cin>>n;
    for(int i=0; i< n; i++){
      cin>>a>>b;
      G[get_id(a)].push_back(get_id(b));
      G[get_id(b)].push_back(get_id(a));
    }

    // solve
    int ans = 0;
    for(int i=0; i < id.size(); i++){
      if(!vis[i] && bfs(i)) ans += 1;
    }
    if(ans == 1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
