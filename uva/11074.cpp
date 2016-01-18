// 11074 - Draw Grid
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2015
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string f="",p="",ss="", no="";
  int s,t,n,len,c=1;
  while(cin>>s>>t>>n && s!=0 && t!=0 && n!=0){
    cout<<"Case "<<c++<<":"<<endl;
    f.clear();
    p.clear();
    ss.clear();
    no.clear();
    len = s*n + t*(n+1);
    for(int i = 0; i < len; i++) f+="*";
    for(int i = 0; i< s; i++) ss+=".";
    for(int i = 0; i< t; i++) p+="*";
    for(int i=0;i<n;i++) no+= p + ss;

    no += p;

    for(int k=0;k<n;k++){
      for(int i=0;i<t;i++)
        cout<<f<<endl;
      for(int i=0;i<s;i++)
        cout<<no<<endl;
    }
    for(int i=0;i<t;i++)
      cout<<f<<endl;

    cout<<endl;
  }
  return 0;

}
