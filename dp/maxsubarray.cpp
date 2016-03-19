//https://www.hackerrank.com/challenges/maxsubarray
#include <bits/stdc++.h>
using namespace std;
#define N_max 100001 //10^5
int A[N_max];


int maxNonContiguous(int N){
  int cont_p = 0, sum_p = 0;
  int min_n = numeric_limits<int>::min();
  for(int i = 0; i < N; i++){
    if(A[i]>=0){
      cont_p++;
      sum_p+= A[i];
    }else{
      if(A[i]>min_n)
        min_n = A[i];
    }
  }
  return (cont_p == 0) ? min_n : sum_p;
}

int maxContiguous(int N, int sumNonContigous){
  int t = 0; //sumas parciales
  int cont_p = 0;
  pair<int, int> intervalo = make_pair(0,0);//Intervalo donde se encuentra la suma mayor
  int s = 0; //suma máxima
  for(int i = 0; i < N; i++){
    if(A[i]>=0) cont_p++;
    t += A[i];
    if(t >= s){
      s = t;//actualiza
      intervalo.second = i;
    }
    else if(t < 0){
      t = 0;//vuelve a empezar a contar
      intervalo.first = i;
      intervalo.second = i;
    }
  }
  return (cont_p == 0) ? sumNonContigous : s;
}

int main(void){
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
      cin >> A[i];
    }
    int nonC = maxNonContiguous(N);
    cout << maxContiguous(N,nonC) << " " << nonC << endl;
  }
  return 0;
}
