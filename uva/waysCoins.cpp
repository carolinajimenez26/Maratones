#include <bits/stdc++.h>
#define MAX 30002
#define D(x) cout << #x " = " << x << endl

using namespace std;

int coins[5] = {1, 5, 10, 25, 50};
long long memo[MAX][5];

long long ways(int value, int type) {
  if (value == 0) return 1;
  if (value < 0) return 0;
  if (type == 5) return 0;
  if (memo[value][type] != -1) return memo[value][type];

  long long ans = ways(value, type + 1) + ways(value - coins[type], type);
  return memo[value][type] = ans;
}

int main() {
  int num;
  memset(memo, -1, sizeof(memo));
  while (cin >> num) {
    long long ans = ways(num, 0);
    if (ans == 1) {
      cout << "There is only 1 way to produce " << num << " cents change." << endl;
    } else {
      cout << "There are " << ans << " ways to produce " << num << " cents change." << endl;
    }
  }
  return 0;
}
