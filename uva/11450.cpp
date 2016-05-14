#include <bits/stdc++.h>
using namespace std;
int b[21][21];
int dp[201][21];
int M,C;

int shop(int A, int g){
  if(A < 0) return numeric_limits<int>::min();
  if(g == C) return M - A;
  if(dp[A][g] != -1) return dp[A][g];
  int ans = -1;
  for(int i=1; i<= b[g][0]; i++){
    ans = max(ans, shop(A - b[g][i], g + 1));
  }
  return dp[A][g] = ans;
}


int main(){
  int n;
  cin >> n;
  while(n--){
    memset(dp, -1, sizeof(dp));
    cin >> M >> C;
    for(int j=0;j<C;j++){
        cin >> b[j][0];
        for(int i=1; i<= b[j][0]; i++){
          cin >> b[j][i];
        }
    }
    int ans = shop(M,0);
    if(ans < 0) cout<<"no solution"<<endl;
    else cout<<ans<<endl;
  }

  return 0;
}
