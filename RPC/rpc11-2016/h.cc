#include <bits/stdc++.h>

using namespace std;

int main(){
  string s, t, w;
  while(cin >> s){
    t = "";
    w = "";
    for(int i=0; i<s.size(); i++){
      if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
        t += s[i];
      }
    }
    w = t;
    reverse(t.begin(), t.end());
    if(w == t) cout << 'S' << endl;
      else cout << 'N' << endl;
  }
  return 0;
}
