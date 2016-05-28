#include <bits/stdc++.h>

using namespace std;
double EPS = 1e-9;
double PI = acos(-1);
struct point {
  double x, y;
  point() {x = y = 0.0;}
  point(double _x, double _y) :  x(_x), y(_y) {}
};

struct vec {
  double x,y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVector(point a, point b){
  return vec(b.x - a.x, b.y -a.y);
}

double dot(vec a, vec b) {return (a.x * b.x + a.y * b.y);}

double norm_sq(vec v){ return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b){
  vec oa = toVector(o, a), ob = toVector(o, b);
  return acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}
 double cross(vec a, vec b){return a.x*b.y - a.y * b.x;}

bool ccw(point p, point q, point r){
  return cross(toVector(p, q), toVector(p,r)) > 0;
}

bool inPolygon(point pt, const vector<point> &P){
  if((int)P.size() == 0) return false;
  double sum = 0;
  for(int i=0; i < (int)P.size()-1;i++){
    if(ccw(pt, P[i], P[i+1]))
      sum += angle(P[i], pt, P[i+1]);
    else sum -= angle(P[i], pt, P[i+1]);
  }
  return fabs(fabs(sum)- 2*PI) < EPS;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--){
    int a,b, x, y;
    cin>>a>>b;
    vector<point> P;
    for (int i = 0; i < a; i++) {
      cin>>x>>y;
      P.push_back(point(x,y));
    }
    P.push_back(P[0]);
    int cont=0;
    for (int i = 0; i < b; i++) {
      cin>>x>>y;
      point P1(x, y);
      if(inPolygon(P1, P))
        cont++;
      else{
        continue;
      }
    }
    cout<<cont<<endl;
  }
  return 0;
}
