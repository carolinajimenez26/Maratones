#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

int n;

void rotate(vector<vector<char> > &T,vector<vector<char> > &M){
  for(int j=0; j<n; j++){
    for(int i=n-1; i>=0; i--){
      T[n-i-1][n-j-1] = M[j][n-i-1];
    }
  }
}

int main(){
  fast;
  string ans="";
  int cont = 0;
  string crypt;
  cin >> n;
  vector<vector<char> > T(n,vector<char>(n)), M(n,vector<char>(n)), ANS(n,vector<char>(n,'@'));
    cont = 0;
    ans = "";

    for(int i=0; i<n; i++){
      for(int j=0;j<n;j++)
        cin >> M[i][j];
    }

    cin >> crypt;
    //cout << "cont : " << cont << endl;
    //cout << "Original" << endl;
    for(int i=0; i<n; i++){
      for(int j=0;j<n;j++){
        //cout << M[i][j];
        if(M[i][j] == '.')
          //ans+=crypt[cont++];
          ANS[i][j] = crypt[cont++];
      }
      //cout << endl;
    }
    //cout << "--------------" << endl;
    //cout << "cont : " << cont << endl;

    rotate(T,M);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        //cout << T[i][j];
        if(T[i][j] == '.')
          //ans+=crypt[cont++];
          ANS[i][j] = crypt[cont++];
      }
      //cout << endl;
    }
    rotate(M,T);
    //cout << "--------------" << endl;
    //cout << "cont : " << cont << endl;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        //cout << M[i][j];
        if(M[i][j] == '.')
          //ans+=crypt[cont++];
          ANS[i][j] = crypt[cont++];
      }
      //cout << endl;
    }
    //cout << "--------------" << endl;
    //cout << "cont : " << cont << endl;
    rotate(T,M);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        //cout << T[i][j];
        if(T[i][j] == '.')
          //ans+=crypt[cont++];
          ANS[i][j] = crypt[cont++];
      }
      //cout << endl;
    }
    //cout<<ans<<endl;
    //cout << "cont : " << cont << endl;
    //cout << "ANS : " << endl;
    bool flag=false;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        if(ANS[i][j]<'a' || ANS[i][j]>'z'){
          flag=true;
          break;
        }else{
          ans+=ANS[i][j];
        }
    }

    if(!flag && ans.size() == n*n) cout<<ans<<endl;
    else cout<<"invalid grille"<<endl;

  return 0;
}
