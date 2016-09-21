#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

struct point {
  double x, y;
  point () { // constructor
    x = y = 0;
  }
  point (double _x, double _y) {
    x = _x;
    y = _y;
  }
  bool operator < (point other){
    if(fabs(x - other.x) > EPS){
      return x < other.x;
    }
    return y < other.y;
  }
};

struct line {
  point p1, p2;
  double m, b;
  line (point _p1, point _p2) {
    p1 = _p1;
    p2 = _p2;
    m = (p2.y - p1.y) / (p2.x - p1.x);
    b = p1.y - (m*p1.x);
  }
};

double getX(line l, double y){
  return ((y - l.b ) / l.m) ;
}

double dist(point p1, point p2){
  return sqrt( ( (p2.x - p1.x)*(p2.x - p1.x) ) + ( (p2.y - p1.y)*(p2.y - p1.y) ) );
}

int main(){
  int cases, N;
  double x, y, maxY, ans = 0.0;
  cin >> cases;
  while (cases--) {
    cin >> N;
    ans = 0.0;
    vector<point> v;
    while (N--) {
      cin >> x >> y;
      point p(x,y);
      v.push_back(p);
    }
    maxY = 0.0;
    sort(v.begin(), v.end());
    for (int i = v.size() - 1 ; i > 0; i-=2) {
      if (v[i-1].y > maxY) {
        line l(v[i],v[i-1]);
        double x0 = getX(l, maxY);
        point np(x0, maxY);
        double d = dist(v[i-1], np);
        ans += d;
        maxY = v[i-1].y;
      }
    }
    cout << fixed << setprecision(2) << ans << endl;
  }
  return 0;
}
