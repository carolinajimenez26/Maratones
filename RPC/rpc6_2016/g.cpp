#include <bits/stdc++.h>

using namespace std;
#define MAX 25
int N, M, T;
int memo[MAX][MAX][1010];
int v[MAX][MAX][1010];

int solver(int i, int j, int t){
  int ans1, ans2, ans3, ans4, ans5;
  if(memo[i][j][t] != -1) return memo[i][j][t];
  if(i <= 0 || j <= 0) return 0;
  if(i > N || j > M) return 0;
  if(t > T) return 0;
  ans1 = solver(i+1, j, t+1) + v[i][j][t];
  ans2 = solver(i, j+1, t+1) + v[i][j][t];
  ans3 = solver(i, j-1, t+1) + v[i][j][t];
  ans4 = solver(i-1, j, t+1) + v[i][j][t];
  ans5 = solver(i, j, t+1) + v[i][j][t];
  return memo[i][j][t] = max(ans1, max(ans2, max(ans3, max(ans4, ans5))));
}

int main(){
  int t,p, x ,y;
  int xi, yi, ti, vi;
  cin >> t;
  while(t--){
    T = 0;
    memset(memo, -1, sizeof memo);
    memset(v, 0, sizeof v);
    cin >> N >> M >> p;
    cin >> x >> y;
    for(int i=1; i<=p; i++){
      cin >> xi >> yi >> ti >> vi;
      v[xi][yi][ti] = vi;
      T = max(T, ti);
    }
    cout << solver(x, y, 0) << endl;
  }
  return 0;
}
