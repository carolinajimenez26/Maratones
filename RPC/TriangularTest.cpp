#include<bits/stdc++.h>
using namespace std;
#define INF numeric_limits<int>::max()
#define MAX 100002
#define MAXTRI 449
int dp[MAX];
vector<int> triNumbers(MAXTRI);

void init(){
  for(int i = 0; i < MAXTRI; i++){
    triNumbers[i] = (i*(i+1))/2;
  }
}

int invGauss(int n){
  return ceil(sqrt(2.0*double(n)));
}


int change(int value){
  int ans = INF, limit= invGauss(value);
  if(value < 0) return INF;
  if(value == 0) return 0; //hoja de la recursión
  if(dp[value]!=-1) return dp[value];
  //cout<<value<<": "<<limit<<endl;
  int tempChange;
  for(int i = 1; i <= limit; i++){
    ans = min(change(value - triNumbers[i]), ans);
  }
  return dp[value] = ans + 1;
}

int main(void){
  memset(dp,-1,sizeof(dp));
  init();
  dp[0] = 0;
  int n;
  while(true){
    cin>>n;
    cout << change(n) << endl;
  }
  return 0;
}
