#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> um;
int N[17][17];
int color[17];
int total_nodes;

bool back_paint(int cur, int MC) {
  if (cur == total_nodes) return true;
  for (int c = 0; c < MC; ++c) {
    color[cur] = c;
    int cool = true;
    for (int j = 0; j < total_nodes; ++j) {
      if (N[cur][j] == 1) {
        if (color[j] == color[cur]) {
          cool = false;
          break;
        }
      }
    }
    if (cool) {
        if (back_paint(cur + 1, MC))
          return true;
    } else {
      color[cur] = -1;
      for(int i = cur + 1; i < total_nodes; i++){
        color[i] = -1;
      }
    }
  }

  return false;
}

int main(int argc, char const *argv[]) {
  int T, c, b;
  cin >> T;
  while(T--){
    cin >> c >> b;
    total_nodes = c;
    memset(N, 0 , sizeof(N));
    memset(color, -1, sizeof(color));
    for(int i=0; i<c; i++){
      um[i] = 1;
    }
    int a, d;
    for(int i=0; i<b; i++){
        cin >> a >> d;
        N[a][d] = 1;
        N[d][a] = 1;
    }
    bool flag = false;
    int Z = 1;
      while(Z <= 4){
        if(back_paint(0, Z)){
          cout << Z << endl;
          flag = true;
          break;
        }
        Z++;
      }
      if(!flag){
        cout << "many" << endl;
      }
    }
  return 0;
}
