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

double distToLine(point p, point a, point b){
  vec ab = toVec(a,b), ap = toVec(a, p);
  double u = dot(ab, ap) / norm_sq(ab);
  //cout << "u:" << u << endl;
  if( u <= EPS ){ // ab_prima esta a la izquierda del segmento
    // el punto no esta dentro del segmento y esta a la izquierda
    return dist(a, p);
  }else if( u - 1.0 >= EPS){ // ab_prima es mayor al segmento
    // el punto no esta dentro del segmento y esta a la derecha
    return dist(b, p);
  }
  point c(0.0, 0.0);
  c = translate(a, scale(ab, u));
  // ab_prima esta dentro del segmento
  return dist(p, c);
}


int main(){
	double x, y, xr, yr, d;
  string n_string;
  int n;

  while(cin >> n_string && n_string != "*"){
    n = atoi(n_string.c_str());
    cin >> xr >> yr;
    d = numeric_limits<double>::max();
    vector<point > v;
    point r(xr,yr);
    for(int i = 0; i < n ; i++){
      cin>> x >> y;
      point p(x,y);
      v.push_back(p);
    }
    v.push_back(v[0]); // para completar el poligono, uno el ultimo punto con el primero
    for(int i=0; i < v.size() -1 ; i++){
      d = min(d, distToLine(r, v[i], v[i+1]));
    }
    cout << fixed << setprecision(3) << d << endl;
  }
	return 0;
}
