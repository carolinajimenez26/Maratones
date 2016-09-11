#include<bits/stdc++.h>
const long long inf = 10000000;
const long long minf = -10000000;
using namespace std;

struct Point{
  long long x;
  long long y;

  Point(){
    x = 0;
    y = 0;
  }
  Point(int _x, int _y): x(_x), y(_y) {}
  bool operator < (Point other) const {
    if( x != other.x)
      return x < other.x;
    return y < other.y;
  }
};

int V[51];


Point f1(Point w, vector<Point> &S){ //A la derecha
  Point ans;
  ans.x = inf;
  ans.y = minf;
  for(int i=0; i<S.size(); i++){
    if(w.y == S[i].y && S[i].x > w.x && !V[i] && S[i].x < ans.x){
      ans = S[i];
    }
  }
  return ans;
}

Point f2(Point w, vector<Point> &S){ //a arriba
  Point ans;
  ans.x = minf;
  ans.y = inf;
  for(int i=0; i<S.size(); i++){
    if(w.x == S[i].x && S[i].y > w.y && !V[i] && S[i].y < ans.y){
      ans = S[i];
    }
  }
  return ans;
}

Point f3(Point w, vector<Point> &S){ //A la izquierda
  Point ans;
  ans.x = minf;
  ans.y = inf;
  for(int i=0; i<S.size(); i++){
    if(w.y == S[i].y && S[i].x < w.x && !V[i] && S[i].x > ans.x){
      ans = S[i];
    }
  }
  return ans;
}

Point f4(Point w, vector<Point> &S){ //A la abajo
  Point ans;
  ans.x = inf;
  ans.y = minf;
  for(int i=0; i<S.size(); i++){
    if(w.x == S[i].x && S[i].y < w.y && !V[i] && S[i].y > ans.y){
      ans = S[i];
    }
  }
  return ans;
}

bool iscool(const Point &p) {
  return p.x != inf && p.x != minf && p.y != inf && p.y != minf;
}

Point next_point(Point curr, int &move, vector<Point> &S, map<Point, int> &id){
  Point ans(minf, minf);
  for(int i=0; i < 4 ; i++){
    bool flag = false;
    if(move == 0){
      ans = f1(curr, S);
      if( iscool(ans) && !V[id[ans]]){
        V[id[ans]] = true;
        move = (move + 1) % 4;
        flag = true;
      }
    }else if(move == 1){
      ans = f2(curr, S);
      if( iscool(ans) && !V[id[ans]]){
        V[id[ans]] = true;
        move = (move + 1) % 4;
        flag = true;
      }
    }else if(move == 2){
      ans = f3(curr, S);
      if( iscool(ans) && !V[id[ans]]){
        V[id[ans]] = true;
        move = (move + 1) % 4;
        flag = true;
      }
    }else {
      ans = f4(curr, S);
      if( iscool(ans) && !V[id[ans]]){
        V[id[ans]] = true;
        move = (move + 1) % 4;
        flag = true;
      }
    }
    if(flag) return ans;
    else {
      move = (move + 1) % 4;
    }
  }

  return ans;
}

int main(){
  int N, x, y, t = 1 ;
  while(cin>>N && N){
    vector<int> ans;
    vector<Point> S;
    map<Point, int> id;
    Point lower(inf,inf);
    memset(V, 0, sizeof V);
    for(int i=0; i < N; i++){
      cin >> x >> y;
      if( y < lower.y){
        lower.y = y;
        lower.x = x;
      }else if( y == lower.y && x < lower.x){
        lower.y = y;
        lower.x = x;
      }
      Point p(x,y);
      id[p] = i;
      S.push_back(p);
    }

    int move = 0;
    Point curr(lower.x, lower.y);
    V[id[curr]] = 1;
    //cout<< curr.x << " " << curr.y << endl;
    while( iscool(curr) ){
      ans.push_back(id[curr]);
      curr = next_point(curr, move, S, id);
      //cout<< curr.x << " " << curr.y << endl;
    }

    cout<<"Polygon #" << t++ << ": ";
    for(int i=0; i < N; i++){
      cout<< (ans[i] + 1);
      if( i < N-1 ) cout << " ";
      else cout << endl;
    }

  }
  return 0;
}
