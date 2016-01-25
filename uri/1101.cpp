//http://www.urionlinejudge.com.br/repository/UOJ_1101_en.html
#include<iostream>

using namespace std;

int main(void){
  int a, b, sum;
  while(true){
    cin >> a >> b;
    if(!(a>0 && b>0)) break;
    if(b > a){
      int tmp = a;
      a = b;
      b = tmp;
    }
    sum = 0;
    for(int i = b; i <= a; i++){
      sum += i;
      cout << i << " ";
    }
    cout << "Sum=" << sum << endl;
  }
  return 0;
}
