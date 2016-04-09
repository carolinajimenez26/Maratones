#include <bits/stdc++.h>
using namespace std;
bool v[10]; //para los números del 0-9
int finalCount = 10;

bool countDigits(int N){
  int res;
  while(N){
    res = N % 10;
    N = N / 10;
    if(v[res] == false){//si no la había visto
      v[res] = true;
      finalCount--;//marcamos como visto
      if(finalCount == 0) return true;//finish
    }
  }
  return false;//not finish
}

void init(){//inicializa v
  finalCount = 10;
  for(int i = 0; i < 10; i++)
    v[i] = false;
}

int main(void){
  int T;//casos
  cin >> T;
  int cases = 1;//para la respuesta Case#x
  while(T--){
    int N;//El número en el que empieza a contar la oveja
    bool finish = false;
    cin >> N;
    if(N == 0) cout << "Case #" << cases << ": INSOMNIA" << endl;
    else{
      init();
      int i = 0, N_aux;
      while(!finish){//empieza a contar
        N_aux = (i+1)*N;//Siguiente número
        finish = countDigits(N_aux);//Hace la cuenta
        i++;
      }
      cout << "Case #" << cases << ": " << N_aux << endl;
    }
    cases++;
  }
  return 0;
}
