// https://www.hackerrank.com/challenges/unbounded-knapsack
#include <bits/stdc++.h>
using namespace std;
#define MAX 2001
int weights[MAX];
int K[MAX];

void initT(int N){
  for(int i=0;i<=N;i++)
    K[i] = 0;
}
/*
*  w : limite de la mochila
*  N : numero de items
*  recorremos por filas:capacidad_wi por cada item
*/
int knapsack(int w, int N){
  initT(w);
  for(int i=1;i<=w;i++){
    for(int j=0;j<N;j++) {
      if(weights[j]<= i)
        K[i] = max(K[i], weights[j] + K[i - weights[j]]);
    }
  }
  return K[w];
}


int main(void){
  int T,N,W;//casos
  cin >> T;
  while(T--){
    cin >> N;
    cin >> W;
    for(int i = 0; i < N; i++)
      cin >> weights[i];
    cout << knapsack(W,N) << endl;
  }
  return 0;
}
