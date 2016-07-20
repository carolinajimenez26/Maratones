#include <bits/stdc++.h>
using namespace std;
#define MAX 1000010
int pebbles[MAX];
bool vis[MAX];
vector<int> ri[MAX];
vector<int> le[MAX];

int BFS(int source, int n){
  int maxi = -1, v, n_idx, nv;
  vis[0] = true;
  queue<int> q;
  q.push(source);
  while(!q.empty()){
    v = q.front();
    q.pop();
    maxi = max(v, maxi);

    // momiviento a la derecha, a cuales puedo llegar
    n_idx = v + pebbles[v];
    if( n_idx < n){
      for(int i=0; i< le[n_idx].size(); i++){
        nv = le[n_idx][i];
        if(!vis[nv]){
          q.push(nv);
          vis[nv] = true;
        }
      }
    }
    // movimiento a la izquierda
    n_idx = v - pebbles[v];
    if(n_idx >= 0){
      for(int i=0; i< ri[n_idx].size(); i++){
        nv = ri[n_idx][i];
        if(!vis[nv]){
          q.push(nv);
          vis[nv] = true;
        }
      }
    }
  }
  return maxi;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, tmp, ans;
  while(cin>>n && n!=0){
    memset(vis, 0, sizeof vis);
    memset(ri, 0, sizeof ri);
    memset(le, 0, sizeof le);
    for(int i=0; i<n; i++){
      cin>>pebbles[i];
    }
    //suma
    for(int i=0; i<n; i++){
      tmp = i + pebbles[i];
      if(tmp < n) ri[tmp].push_back(i);
    }
    //resta
    for(int i=0; i<n; i++){
      tmp = i - pebbles[i];
      if(tmp >= 0){
        le[tmp].push_back(i);
        /*
        if(ri[tmp].size()>0){
          addEdge(i, ri[tmp]);
        }
        */
      }
    }
    cout<<BFS(0, n)<<endl;
  }
  return 0;
}
