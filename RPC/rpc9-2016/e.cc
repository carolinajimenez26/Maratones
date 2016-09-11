#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<string> > um;

int main(){
  int N, W, vl;
  string a;
  cin >> N;
  while(N--){
    cin >> a;
    vl = a.size();
    um[vl].push_back(a);
  }
  cin >> W;
  int cont = 0, nro=1;
  while(W--){
    cont = 0;
    cin >> a;
    vl = a.size();
    cout<<"Word #"<<nro++<<": "<<a<<endl;
    if(um.count(vl)){
      vector<string> tmp = um[vl];
      for(int i=0; i< tmp.size(); i++){
        string wd = tmp[i];
        bool flag = true;
        for(int j=0; j < vl; j++){
          if(a[j] != '-' && a[j] != wd[j]){
            flag = false;
            break;
          }
        }
        if(flag){
          cont+=1;
          cout<<wd<<endl;
        }
      }
      cout<<"Total number of candidate words = "<<cont<<endl;
    }
  }
  return 0;
}
