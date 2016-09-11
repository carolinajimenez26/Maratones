#include <bits/stdc++.h>

using namespace std;

int A[5];

void make_positive(int neg){
  int pv = 1500, index;
  int k = 0;
  while(true){
    int cont = 0;
    for(int i=0; i<5; i++){
      if(A[i] < 0) cont += 1;
      if(A[i] < 0){
        pv = A[i];
        index = i;
      }
    }
    if(cont == 0 ) break;

    int r = (index + 1) % 5;
    int l = (index -1 + 5) % 5;
    A[r] += pv;
    A[l] += pv;
    A[index] *= (-1);
    for(int i=0; i<5; i++){
      if(A[i] < 0) cont += 1;
    }
    if(cont == 0 ) break;
    k++;
  }
}

int main(){
  int N, n, k=1;
  cin >> N;
  while(N--){
    n=0;
    for(int i=0; i<5; i++){
      cin >> A[i];
      if(A[i] < 0) n++;
    }
    make_positive(n);
    cout<< "Pentagon #"<<k++<<":"<<endl;
    for(int i=0; i<5; i++){
      cout << A[i] << ((i < 4) ? ' ' : '\n');
    }
  }
  return 0;
}
