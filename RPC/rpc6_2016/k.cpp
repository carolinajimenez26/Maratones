#include <bits/stdc++.h>

using namespace std;

int n;

int v[26][26];
int A[6][6];

bool isCorrect(){
  int sumr, sumc, sumg;
  if(n == 1) return true;
  if(n == 2) return false;
  for(int i=0; i<n; i++){
    sumr=0, sumc=0;
    for(int j=0; j<n; j++){
      sumr += v[i][j];
      sumc += v[j][i];
    }
    if(sumr != (n*(n+1))/2 || sumc != (n*(n+1))/2) return false;
  }
  int rn = sqrt(n);
  for (int j = 0; j < n; j++) {
    for(int i=0; i < n; i++){
      A[j/rn][i/rn]+= v[j][i];
    }
  }

  for(int i=0; i<rn; i++){
    for(int j=0; j<rn; j++){
      if (A[i][j] != (n*(n+1))/2) return false;
    }
  }
  return true;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    memset(A,0,sizeof A);
    cin >> n;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> v[i][j];
      }
    }
    if(isCorrect()){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }

return 0;
}
