#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
void init(){
  m['a'] = 0;
  m['b'] = 1;
  m['c'] = 2;
  m['d'] = 3;
  m['e'] = 4;
  m['f'] = 5;
  m['g'] = 6;
  m['h'] = 7;
}

bool table[10][10];

int x[] = {-2,-1,1,2, 2, 1, -1,-2};
int y[] = { 1, 2,2,1,-1,-2,-2, -1};

bool isValid(int row, int col){
  if (row >= 0 && row < 8 && col >= 0 && col < 8 ) return true;
  return false;
}

pair<int, int> converter(string p){
  int row = 8 - (p[1] - 48);
  return make_pair(row, m[ p[0] ]);
}

int bfs(string source, string target) {
  pair<int, int> s = converter(source);
  pair<int, int> t = converter(target);
  queue<pair< pair< int, int> , int > > q; // q.first pos,
                                            // q.second depth
  q.push(make_pair(s,0));
  table[s.first][s.second] = true; // visited
  while (!q.empty()) {
    pair<int, int> pos = q.front().first;
    int depth = q.front().second;
    q.pop();
    if (pos == t) return depth;
    for (int i = 0; i < 8; i++) {
      int new_x = pos.first + x[i];
      int new_y = pos.second + y[i];
      if (isValid(new_x,new_y) && !table[new_x][new_y]) {
        q.push(make_pair(make_pair(new_x,new_y), depth + 1));
        table[new_x][new_y] = true;
      }
    }
  }

  return -1;
}

int main(){
  init();
  string from, to;
  while (cin >> from >> to){
    memset(table, 0, sizeof table);
    cout << "To get from " << from << " to " << to
    << " takes " << bfs(from, to) << " knight moves." << endl;
  }
  return 0;
}
