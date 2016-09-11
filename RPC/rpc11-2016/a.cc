#include <bits/stdc++.h>

using namespace std;

int main(){
  int A, B, C;
  int act;
  while(cin >> A >> B >> C){
    if(A == B || B == C || C == A){
      cout << 'S' << endl;
    }else if(A == (B + C) ||  B == (C + A) || C == (B + A)){
      cout << 'S' << endl;
    }else{
      cout << 'N' << endl;
    }
  }
  return 0;
}
