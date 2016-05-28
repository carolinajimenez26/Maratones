#include <bits/stdc++.h>
using namespace std;
int N,M;
int maze[310][310];
int dp[310][310];

int f(int i, int c , int n){
  if(i>=n) return 0;
  if(dp[i][c]!=-1) return dp[i][c];
  int ans1 = f(i+1,c,n);
  int ans2 = f(i+2,c,n) + maze[i][c];
  return dp[i][c] = max(ans1,ans2);
}

int solver(){
  int sum = 0;
  memset(dp, -1, sizeof dp);
  for(int i=0;i<M;i++){
    sum = f(0,i,N);
    maze[i][0] = sum;
  }
  memset(dp, -1, sizeof dp);
  return f(0,0,M);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  while(cin>>N>>M){
    for(int i=0; i<N; i++){
      for(int j=0; j<M;j++)
        cin>>maze[i][j];
    }
    int ans = solver();
    cout<<ans<<endl;
  }

  return 0;
}
