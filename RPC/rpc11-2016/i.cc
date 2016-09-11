#include <bits/stdc++.h>
using namespace std;
#define MAX 50000
int v1[MAX], v2[MAX], v[MAX];

void print(int *vec, int n){
  for(int i=0; i < n; i++){
    cout << vec[i] << " ";
  }
  cout << endl;
}
int main(){

  int n, cont;
  while(cin >> n){
    for(int i = 0 ; i < n; i++){
      cin>>v[i];
    }
    //print(v, n);
    // derecha
    cont = 1;
    for(int i = 0; i < n; i++){
      if(v[i] >= cont){
        v1[i] = cont;
        cont += 1;
      }
      else{
        v1[i] = v[i];
        cont = v[i] + 1;
      }
    }
    //print(v1, n);
    // izquierda
    cont = 1;
    for(int i = n-1; i >= 0; i--){
      if(v[i] >= cont){
        v2[i] = cont;
        cont += 1;
      }
      else{
        v2[i] = v[i];
        cont = v[i] + 1;
      }
    }
    //print(v2, n);

    // answer
    int ans = -1;
    for(int i = 0; i < n; i++){
      if(v1[i] == v2[i] && v1[i] > ans){
        ans = v1[i];
      }

      if(i > 0 && i < n-1){
        int mini = min(v1[i], v2[i]);
        if(mini > ans && v1[i - 1] >= mini -1 && v2[i - 1] >= mini -1)
          ans = v1[i];
      }

    }

    cout<< ans << endl;
  }



  return 0;
}
