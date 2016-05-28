#include <bits/stdc++.h>
using namespace std;
int main(){
  int T,n,ans;
  cin>>T;
  while(T--){
    cin>>n;
    ans = (pow(n,4) - 6*pow(n,3) + 23*pow(n,2) - 18*n +24)/24;
    cout<<ans<<endl;
  }
  return 0;
}
