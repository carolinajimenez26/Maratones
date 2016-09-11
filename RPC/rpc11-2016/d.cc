#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int d_v, n_dv, mult, n_mult;
  while(cin >> d_v >> n_dv >> mult >> n_mult){
    bool flg = 0;
    for(int i=1; i*i <= mult; i++ ){
      int n = d_v*i;
      if(n%d_v == 0 && n%n_dv != 0 && mult%n == 0 && n_mult%n != 0){
        cout << n << endl;
        flg = 1;
        break;
      }
    }
    if(!flg){
      cout << "-1" << endl;
    }
  }
  return 0;
}
