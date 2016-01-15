// 10790 - How Many Points of Intersection?
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1731
#include <bits/stdc++.h>
using namespace std;

int main(){
	int c1=0;
	long long a, b, r;
	while(cin >> a && a != 0 && cin >> b && b!=0){
		c1++;
        r = (a *(a-1)/2)*(b *(b-1)/ 2);
		cout << "Case " << c1 << ": " << r << endl;
	}
	return 0;
}
