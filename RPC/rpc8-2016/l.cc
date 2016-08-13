#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, t, cr=1000001, ac;
  cin >> n;
  while(n--){
    ac = 0;
    while(cin >> t && t){
      if(t <= cr*2){
        cr = t;
      }else{
        ac += t - cr*2;
        cr = t;
      }
    }
    cout << ac << endl;
  }
  return 0;
}
