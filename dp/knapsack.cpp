#include <bits/stdc++.h>
using namespace std;
#define N_max 100000//inicialmente
int weights[N_max];//pesos de cada item
int values[N_max];//valores de cada item


/*
*  i : item
*  j : weight current, j = w_max - w[item]
*  recorremos los items de derecha a izquierda en el arreglo
*/
int mochila(int i, int j){
  if(i == 0 || j == 0) return 0; //si terminó de recorrer los índices o ya no tiene más capacidad en la mochila
  if(weights[i-1] > j)
    return mochila(i-1,j);//si el peso del item siguiente es mayor al peso que llevamos,
                          //toma el siguiente item
  if(weights[i-1] <= j) //si el peso del item siguiente es menor o igual al peso que llevamos
    return max(mochila(i-1,j),values[i-1]+mochila(i-1,j-weights[i-1]));
    //puede agregar o no ese item a la mochila
}

int main(void){
  int T;//casos
  cin >> T;
  while(T--){
    int N;//tamaño arreglo
    cin >> N;
    int max_w;//peso que soporta la mochila
    cin >> max_w;
    for(int i = 0; i < N; i++){
      cin >> weights[i];//agrega peso del elemento i
      cin >> values[i];//agrega valor del elemento i
    }
    cout << mochila(N,max_w) << endl;
  }
  return 0;
}
