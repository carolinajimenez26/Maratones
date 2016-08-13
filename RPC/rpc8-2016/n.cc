#include <bits/stdc++.h>
using namespace std;

void cmp(vector<int> &a, vector<int> &b, int sa, int sb){
  bool ans = 0;
  if(sa > sb) ans = 1;
  if(a[0] > b[0]){
    cout<<((ans == 1) ? "both" : "color")<<endl;
    return;
  }else if(a[0] == b[0]){
    if(a[1] > b[1]){
      cout<<((ans == 1) ? "both" : "color")<<endl;
      return;
    }else if(a[1] == b[1]){
      if(a[2] > b[2]){
        cout<<((ans == 1) ? "both" : "color")<<endl;
        return;
      }
    }
  }
  if(ans == 1) cout <<"count"<<endl;
  else cout<<"none"<<endl;
}

int main(){
  int n;
  cin>>n;
  for(int i=0; i < n; i++){
    vector<int> a(3), b(3);
    int sa=0, sb=0;
    for(int j=0; j<3; j++){
      cin>>a[j];
      sa += a[j];
      cout<<a[j]<<" ";
    }
    for(int j=0; j<3; j++){
      cin>>b[j];
      sb += b[j];
      cout<<b[j]<<((j < 2) ? ' ' : '\n');
    }
    cmp(a,b,sa,sb);
  }

  return 0;
}
