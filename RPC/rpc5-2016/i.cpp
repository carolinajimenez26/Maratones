#include <bits/stdc++.h>
using namespace std;
pair<double,int> VA[510];
vector<int> splitInt(string s){
  stringstream ss(s);
  vector<int> v;
  int tok;
  while(ss>>tok)
    v.push_back(tok);
  return v;
}
vector<double> splitDouble(string s){
  stringstream ss(s);
  vector<double> v;
  double tok;
  while(ss>>tok)
    v.push_back(tok);
  return v;
}

void init(int n){
  for(int i=0;i<n;i++){
    VA[i] = make_pair(0.0,0);
  }
}

int C[505];
int main(){
  int T,A,B;
  vector<int> vi;
  vector<double> vd;
  int tot = 0;
  string s;
  getline(cin,s);
  vi = splitInt(s);
  T = vi[0];
  while(T--){
    long long tot = 0;
    getline(cin,s);
    vi = splitInt(s);
    A = vi[0];
    B = vi[1];

    init(A);

    for(int i=0;i<B;i++){
      getline(cin,s);
      vd = splitDouble(s);
      for(int j=0;j<A;j++){
        VA[j].first+= (vd[j]/double(100.0))*vd[A];
        VA[j].second = j+1;
      }
      tot+= (long long)(vd[A]);
    }
    sort(VA,VA+A, greater<pair<int,int> >());
    pair<int,int> f = VA[0] , s = VA[1];
    if((long long)(2*f.first) > tot){
      cout<<f.second<<" "<<f.first<<endl;
    }else if(f.first > s.first){
      cout<<f.second<<" "<<f.first<<endl;
      cout<<s.second<<" "<<s.first<<endl;
    }else{
      cout<<s.second<<" "<<s.first<<endl;
      cout<<f.second<<" "<<f.first<<endl;
    }
    if(T!=0)
      cout<<endl;
  }
  return 0;
}
