#include <bits/stdc++.h>
#define N 101
#define MAX 15000
#define INF 1000000

using namespace std;
int value, n;
vector<int> coins(N);
pair<int, int> memo[N][MAX];
bool seen[N][MAX];

pair<int, int> solve(int id, int acum) {
  if (acum >= value)
    return make_pair(0, 0);
  if (id == n && acum < value)
    return make_pair(INF, INF);
  if (seen[id][acum])
    return memo[id][acum];

  pair<int, int> ans1 = solve(id+1, acum);
  pair<int, int> ans2 = solve(id+1, min(acum + coins[id], MAX));

  ans2.first += coins[id];
  ans2.second += 1;
  seen[id][acum] = true;
  return memo[id][acum] = min(ans1, ans2);
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> value >> n;
    for (int i = 0; i < n; i++) {
      cin >> coins[i];
    }
    memset(seen, false, sizeof(seen));
    pair<int, int> ans = solve(0, 0);
    cout << ans.first << " " << ans.second << endl;
  }
  return 0;
}
