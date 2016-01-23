// 7001 - Bus Problem
// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=5013

// Kruskal algorithm : https://www.youtube.com/watch?v=fAuF0EuZVCk&list=PLrmLmBdmIlpu2f2g8ltqaaCZiq6GJvl1j&index=5
// make_set, find_set, link, merge : https://www.youtube.com/watch?v=ID00PMy0-vE&list=PLrmLmBdmIlpu2f2g8ltqaaCZiq6GJvl1j&index=4

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 499500

struct edge{
  int start, end;
  long long weight;
  bool operator < (const edge &that) const{
    // si se desea encontrar el arbol de recubrimiento
    // de maxima suma, cambiar el < por un >
    return weight < that.weight;
  }
};

vector<edge> G(MAX);
int p[MAX];

void make_set(int x){ p[x] = x; }
int find_set(int x){
  return (x != p[x]) ? p[x] = find_set(p[x]) : p[x];
}
void union_set(int x, int y){
  int px = find_set(x);
  int py = find_set(y);
  if(px == py) return;
  p[px] = py;
}

//El grafo debe ser no dirigido!
long long kruskal(vector<edge> &G, int r){
  long long total = 0;
  sort(G.begin(), G.begin() + r); // Ordeno hasta el numero de edge, de cada caso
  for (int i = 0; i < r; i++) {
    make_set(i);
  }
  for(int i=0; i< r; i++){
    int u = G[i].start, v = G[i].end;
    long long w = G[i].weight;
    if(find_set(u) != find_set(v)){
      //total += w; // Pesos del MST
      union_set(u, v);
    }else
      total += w; // Pesos de aristas que no son parte del MST
  }
  return total;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, c, r;
  cin>>n;
  while(n--){
    cin>>c>>r;
    for (int i = 0; i < r; i++)
      cin>>G[i].start>>G[i].end>>G[i].weight;
    cout<<kruskal(G, r)<<endl;
  }
  return 0;
}
