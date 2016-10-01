#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

struct point {
  double x, y;
  point () { // constructor
    x = y = 0.0;
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

struct vec {
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2){
  return sqrt( ( (p2.x - p1.x)*(p2.x - p1.x) ) + ( (p2.y - p1.y)*(p2.y - p1.y) ) );
}

point translate(point a, vec b ){
  return point(a.x + b.x, a.y + b.y);
}

vec scale(vec a, double u){
  return vec(a.x*u, a.y*u);
}

double dot(vec a, vec b){
  return a.x*b.x + a.y*b.y;
}

double norm_sq(vec a){
  return a.x*a.x + a.y*a.y;
}

vec toVec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y);
}

double distToLine(point p, point a, point b, point &c){
  vec ab = toVec(a,b), ap = toVec(a, p);
  double u = dot(ab, ap) / norm_sq(ab);
  //cout << "u:" << u << endl;
  if( u <= EPS ){ // ab_prima esta a la izquierda del segmento
    c.x = a.x, c.y = a.y;
    return dist(a, p);
  }else if( u - 1.0 >= EPS){ // ab_prima es mayor al segmento
    c.x = b.x, c.y = b.y;
    return dist(b, p);
  }

  c = translate(a, scale(ab, u));
  // ab_prima esta dentro del segmento
  return dist(p, c);
}


int main(){
	double x, y, xm, ym, d, tmp;
  int n;

  while(cin >> xm >> ym){
    d = numeric_limits<double>::max();
    vector<point > v;
    point m(xm,ym);
    cin >> n;
    for(int i = 0; i < ((2*n) + 2) / 2; i++){
      cin>> x >> y;
      point p(x,y);
      v.push_back(p);
    }
    point ans(0.0,0.0);
    point c(0.0,0.0);
    for(int i=0; i < v.size() - 1; i++){
      tmp = distToLine(m, v[i], v[i+1], c);
      if (tmp < d) {
        d = tmp;
        ans.x = c.x, ans.y = c.y;
      }
    }
    cout << fixed << setprecision(4) << ans.x << endl << ans.y << endl;
  }
	return 0;
}
