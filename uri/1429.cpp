//https://www.urionlinejudge.com.br/judge/es/problems/view/1429
#include<bits/stdc++.h>

using namespace std;

int tonum(char &s){
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

int fact(int x, int result = 1){
  if (x == 1 || x == 0) return result;
  else return fact(x - 1, x * result);
}

int main(void){
  string n;
  while(cin >> n){
    if(n == "0") break;
    int sum = 0;
    int aux = 0;
    for(int i = n.size(); i > 0; i--){//recorremos de izquierda a derecha
      sum += fact(i) * tonum(n[aux]);
      aux++;
    }
    cout << sum << endl;
  }
  return 0;
}
