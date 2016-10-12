#include <bits/stdc++.h>
using namespace std;

struct point{
	int x,y;
	point(){
		x = y = 0;
	}
	point (int _x, int _y) {
    x = _x;
    y = _y;
  }

	point& operator =(const point& a){
    x = a.x;
    y = a.y;
    return *this;
	}
};

struct vect{
	int x,y;
	vect(point a, point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
};

point translate(point a, vect v){
	return point(a.x+v.x, a.y+v.y);
}

int cross(vect a, vect b){
	return a.x*b.y - a.y*b.x;
}

int main(void){
	int cases, ax,ay,bx,by,cx,cy;
	cin >> cases;
	for(int i = 1; i <= cases; i++){
		cin >> ax >> ay >> bx >> by >> cx >> cy;
		point b(bx,by), c(cx,cy), a(ax,ay);
		vect bc(b,c), ab(a,b);
		int area = cross(ab,bc);
		point d = translate(a,bc);
		cout << "Case " << i << ": " << d.x << " " << d.y << " " << abs(area) << endl;
	}
	return 0;
}
