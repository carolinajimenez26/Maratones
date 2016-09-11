#include <bits/stdc++.h>
typedef long long lli;
using namespace std;
int C[8];
lli memo[10][110];

lli DP(int i, int N){
  lli ans=0;
  if(i==8) return N==0;
  if(memo[i][N] != -1) return memo[i][N];
  ans = DP(i+1, N);
  for(int x=1; N - (x*C[i]) >= 0; x++){
    ans += DP(i+1, N-(x*C[i]));
  }
  return memo[i][N] = ans;
}

int main(){
  int T, N, a=1;
  cin >> T;
  while(T--){
    memset(memo, -1, sizeof memo);
    for(int i=0; i<8; i++){
      cin >> C[i];
    }
    cin >> N;
    cout << "Equation #" << a++ << ": " << DP(0, N) << endl;
  }
  return 0;
}
