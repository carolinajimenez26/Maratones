#include <bits/stdc++.h>
using namespace std;
#define MAX 105
#define TMAX 10
#define endl '\n'
vector<unsigned long long> G[MAX];
unsigned long long M[MAX][TMAX], t, n;

void solve(){
  for(int i=0; i<t; i++){
    for(int j=0;j<n;j++){
      if(M[j][i] != 0){
        unsigned long long temp = M[j][i];
        M[j][i] = 0;
        for(int k=0;k<G[j].size();k++){
          M[G[j][k]][i+1]+=temp;
        }
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  unsigned long long m,s,x,y;
  cin>>n>>m>>s>>t;
  memset(M,0,sizeof M);
  M[s][0] = 1;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  solve();
  unsigned long long ans = 0;
  for(int i=0;i<n;i++){
    ans+=M[i][t];
  }
  cout<<ans<<endl;
  return 0;
}
