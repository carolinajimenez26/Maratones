#include <bits/stdc++.h>

using namespace std;

int main(){
  long long T, D, K, lowest;
  string name;
  vector<string> vW;
  vector<pair< string, pair<long long, long long> > > vL;
  cin >> T;
  while(T--){
    lowest = -1;
    //To Winners
    vW.clear();
    vL.clear();
    for(int i=0; i<5; i++){
      cin >> name >> K >> D;
      if(D != 0 && K*3 < D){
        vW.push_back(name + " plz uninstall");
      }
    }
    //To Losers
    for(int j=0; j<5; j++){
      cin >> name >> K >> D;
      vL.push_back(make_pair(name + " plz uninstall",make_pair(K,D)));
      lowest = max(lowest,D);

    }

    for(int i=0; i<vL.size();i++){
      if(vL[i].second.second == lowest)
        vW.push_back(vL[i].first);
      else if(vL[i].second.first*2 < vL[i].second.second)
        vW.push_back(vL[i].first);
    }
    for(int i=0;i<vW.size();i++){
      //  cout<<vW[i]<<endl;
      if(i==vW.size()-1 && T==0)
        cout<<vW[i];
      else
        cout<<vW[i]<<endl;
    }
  }
  return 0;
}
