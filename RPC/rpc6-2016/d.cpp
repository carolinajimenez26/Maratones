#include <bits/stdc++.h>

using namespace std;
int M[102][102];
int r, c;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};

char valid(int x, int y){
  if(x < 0 || x>r+1 || y < 0 || y>c+1 )
    return -2;
  return M[x][y];
}

bool fill(int ref){
  int cont;
  bool flag = false;
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      cont = 0;
      if(M[i][j] == -1 ){
        for(int k=0; k<4; k++){
          if(valid(i+dx[k],j+dy[k]) == ref-1)
            cont+=1;
        }
        if(cont>=1){
          M[i][j] = ref;
          flag = true;
        }
      }
    }
  }
  return flag;
}

void printM(int points){
    string s;
    if(points==1){
      s=".";
      for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
          if(M[i][j]==0)
            cout<<s<<".";
          else
            cout <<s<<M[i][j];
        }
        cout << endl;
      }
    }
    else{
      for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
          if(M[i][j]==0)
            cout<<"...";
          else{
            if(M[i][j] < 10)
              cout<<".."<<M[i][j];
            else
              cout<<"."<<M[i][j];
          }
        }
        cout << endl;
      }
    }



}

int main(){
  cin >> r >> c;

  //memset(M,-1,sizeof(M));
  //col 0 and c+1
  for(int i=0; i<=r+1; i++){
    M[i][0] = 0;
    M[i][c+1] = 0;
  }
  //row 0 and r+1
  for(int i=0; i<=c+1; i++){
    M[0][i] = 0;
    M[r+1][i] = 0;
  }
  char tmp;
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      cin>>tmp;
      if(tmp == '.')
        M[i][j] = 0;
      else
        M[i][j] = -1;
    }
  }

  for(int i=1;i<=50;i++){
      if(!fill(i)){
        if(i-1 < 10){
          printM(1);
          break;
        }else{
          printM(3);
          break;
        }
      }
    //  cout << "Anillos: " <<i << endl;
  }
return 0;
}
