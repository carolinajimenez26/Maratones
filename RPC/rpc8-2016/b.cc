#include <bits/stdc++.h>
using namespace std;
int main(){
  //ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t,n,a;
  cin >> t;
  while(t--){
    cin >> n;
    vector<int> v(n+1), ans;
    int m = -1;
    for(int i=0; i<n; i++){
      cin >> a;
      v[a-1] = i;
    }
    for(int i=0; i< n; i++){
      a = v[i];
      m = max(a,m);
      if(a < m) ans.push_back(i+1);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i=0; i< ans.size(); i++)
      cout<< ans[i] <<endl;
  }
  return 0;
}
