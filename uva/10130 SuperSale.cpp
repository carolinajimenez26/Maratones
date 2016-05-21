#include <bits/stdc++.h>

using namespace std;
#define NMAX 1100
#define WMAX 50
int P[NMAX];
int W[NMAX];
int memo[NMAX][WMAX];

int N,G,T,MW,ans;

int solver(int id, int v){
  if(id == N || v <= 0) return 0;
  if(memo[id][v]!= -1) return memo[id][v];
  if(W[id] > v) return memo[id][v] = solver(id + 1, v);
  int ans1 = solver(id+1, v);
  int ans2 = P[id] + solver(id+1, v - W[id]);
  return memo[id][v] = max(ans1,ans2);
}

int main(){
  cin >> T;
  while(T--){
    memset(memo, -1, sizeof memo);
    cin >> N;
    for(int i=0; i<N; i++){
      cin >> P[i] >> W[i];
    }
    ans = 0;
    cin >> G;
    for(int i=0; i<G; i++){
      cin>>MW;
      ans+= solver(0, MW);
    }
    cout<<ans<<endl;
  }
return 0;
}
