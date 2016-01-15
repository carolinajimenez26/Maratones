// EZDIJKST - Easy Dijkstra Problem
// http://www.spoj.com/problems/EZDIJKST/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair< int, int>
#define mp(a,b) make_pair(a,b)
vector< pair<int,int> > G[100002];
int dist[100002];
bool visited[100002];

void init(int n){
  for(int i=1;i<=n;i++){
    dist[i] = numeric_limits<int>::max();
    visited[i] = false;
    G[i].clear();
  }
}

int Dijsktra(int source, int target){
  dist[source] = 0;
  priority_queue< pii, vector< pii >, greater< pii> > pq;
  pq.push(mp(0,source));

  while(!pq.empty()){
    int v = pq.top().second, w = pq.top().first;
    //cout<<"V: "<<v<<" W: "<<w<<endl;
    pq.pop();
    if(v == target)
      return w;

    if(visited[v])
      continue;
    visited[v] = true;

    for(int i=0; i< G[v].size(); i++){
      int nv = G[v][i].first, nw = G[v][i].second;
      if(!visited[nv]){
        int new_w = w + nw;
        if(new_w < dist[nv]){
          dist[nv] = new_w;
          pq.push(mp(new_w,nv));
        }
      }
    }
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ca,V,K,A,B,a,b,c,ans=0;
  cin>>ca;
  while(ca--){
    cin>>V>>K;
    init(V);
    for (int i = 0; i < K; i++) {
      // Built the graph
      cin>>a>>b>>c;
      G[a].push_back(make_pair(b,c));
    }
    cin>>A>>B;
    ans = Dijsktra(A,B);
    if(ans == -1)
      cout<<"NO"<<endl;
    else
      cout<<ans<<endl;
  }
  return 0;
}
