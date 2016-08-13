#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, a, ans=0 ;
  cin>>n;
  for(int i=0; i < n; i++){
    ans = 0;
    for(int j=0; j<10; j++){
      cin>>a;
      if(a == 17) ans+=1;
      if(a == 18) ans+=2;
      cout<<a<<((j < 9) ? ' ' : '\n');
    }
    if(ans == 0) cout<<"none"<<endl;
    else if(ans == 1) cout<<"zack"<<endl;
    else if(ans == 2) cout<<"mack"<<endl;
    else cout<<"both"<<endl;
  }

  return 0;
}
