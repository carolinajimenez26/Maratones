// SHPATH - The Shortest Path
// www.spoj.com/problems/SaHPATH/
#include <bits/stdc++.h>
using namespace std;
vector< pair<int, int > > G[10001];
bool visited[10001];
int dist[10001];

void init1(int n){
  for(int i=1; i<=n; i++){
    G[i].clear();
  }
}

void init2(int n){
  for(int i=1; i<=n; i++){
    dist[i] = numeric_limits<int>::max();
    visited[i] = false;
  }
}

int Dijkstra(int source, int target){
  dist[source] = 0;
  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
  pq.push(make_pair(0, source));

  while(!pq.empty()){
    int v = pq.top().second, w = pq.top().first;
    pq.pop();
    if(visited[v])
      continue;
    visited[v] = true;

    if(v == target)
      return w;

    for(pair<int, int> x : G[v]){
      int nv = x.first, nw = x.second;
      if(!visited[nv]){
        int new_w = w + nw;
        if(new_w < dist[nv]){
          dist[nv] = new_w;
          pq.push(make_pair(new_w, nv));
        }
      }
    }
  }

  return -1;
}


int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int s,n,p,nr,cost,r,ans=0;
  unordered_map<string, int> labels;
  string city, city1,city2;
  for(int i=1; i<=10001; i++)
    dist[i] = numeric_limits<int>::max();
  cin>>s;
  while(s--){
    cin>>n; // numero ciudades
    // Limpiar el grafo
    init1(n);
    for(int i=1; i<=n; i++){
      cin>>city;
      labels[city] = i;
      cin>>p; // numero vecinos
      for(int j=0;j<p;j++){
        cin>>nr>>cost;
        G[i].push_back(make_pair(nr,cost));
      }
    }
    cin>>r; // numero consultas
    for(int j=0; j<r; j++){
      cin>>city1>>city2;
      cout<<Dijkstra(labels[city1],labels[city2])<<'\n';
      //limpiar los visitados y distancias
      init2(n);
    }
  }

  return 0;
}
