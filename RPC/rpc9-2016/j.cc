#include <bits/stdc++.h>
using namespace std;
#define MAX 510
#define endl '\n'
int memo[MAX][MAX];
int V[MAX];
int s;

int dp(int i, int k){
  if( i == s) return 0;
  if(memo[i][k] != -1) return memo[i][k];

  int ans = dp(i+1, k);
  if( i == 0 || ((k + 1) <= (i+1) / 2) ){
    ans = max(ans, dp(i+1, k+1) + V[i]);
  }
  return memo[i][k] = ans;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t, j = 1;
  cin>> t;
  while(t--){
    memset(memo, -1, sizeof memo);
    cin>>s;
    for(int i=0; i<s; i++){
      cin>> V[i];
    }
    cout << "Spree #" << j++ << ": " << dp(0,0) << endl;
  }
  return 0;
}
