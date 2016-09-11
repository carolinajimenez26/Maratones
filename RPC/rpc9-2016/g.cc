#include <bits/stdc++.h>
using namespace std;
#define MAXV 10010
int r,c;
int memo[110][110];
int value[110][110];
bool isvalid(int x, int y){
  if( x >= 0 && x <r && y>=0 && y<c) return true;
  return false;
}
int dp(int x, int y){
  if(!isvalid(x,y)) return 0;
  if(x == r && y == c) return 0;
  if(memo[x][y] !=-1) return memo[x][y];
  int ans1 = dp(x, y+1) + value[x][y];
  int ans2 = dp(x+1, y) + value[x][y];

  return memo[x][y] = max(ans1, ans2);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t,s, ta, right, down, node, cont=1;
  string v;
  cin>>t;
  while(t--){
    memset(memo,  -1 , sizeof(memo));
    cin>>r>>c;

    for(int i=0; i < r; i++){
      for(int j=0; j< c; j++){
        cin>>v;
        int pos = i*c + j;
        if(pos == 0 || pos == r*c -1) value[i][j] = 0;
        else value[i][j] = atoi(v.c_str());
        //va[i*c + j] = v;
      }
    }
    cout<<"Game Board #"<<cont++<<": "<< dp(0,0) << endl;
  }

  return 0;
}
