#include <bits/stdc++.h>

using namespace std;
#define MAXE 100010
#define MAXW 100000010
int E[MAXE],M,W;

int main(){
  int T;
  cin>>T;
  while(T--){
    cin>>M>>W;
    for(int i=0;i < M; i++){
      cin>>E[i];
    }
    int cont = 0;
    sort(E, E+M);
    for(int i=0; i< M; i++)
      if(W>=0 && E[i]<=W){
        W-=E[i];
        cont+=1;
      }
    cout<<cont<<endl;
  }

  return 0;
}
