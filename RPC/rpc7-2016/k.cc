#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, ac=0, it=0;
  while(cin>>N && N){
    it++;
    ac += N;
    if(ac >= 50){
      if(ac >= 100){
        cout << "Input #" << it << ": Totally Sweet!" << endl;
      }else{
        cout << "Input #" << it << ": Sweet!" << endl;
      }
      ac %= 50;
    }
  }
  return 0;
}
