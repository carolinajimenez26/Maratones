#include <bits/stdc++.h>

using namespace std;

int count(string s, int l){
  int cont=0;
  for(int i=0;i<l;i++){
    cont += s[i] - 48;
  }
  return cont;
}

void smaller(string &s, int l){
  for(int i=l-1; i>=0; i--){
    if(s[i]!='0'){
      s[i] -= 1;
      return;
    }
    else{
      continue;
    }
  }
}

int main(){
  string s;
  int len;
  while(cin>>s && s!="END"){
    len = s.size();
    if(count(s,len) == 1)
      cout<<"0"<<endl;
    else{
      smaller(s,len);
      cout<<s<<endl;
    }
  }
  return 0;
}
