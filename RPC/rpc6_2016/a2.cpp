#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

int F[MAX];
vector<bitset<MAX> > E(MAX);

int find_set(int x){
  return (F[x]==x) ? x : F[x] = find_set(F[x]);
}

void union_set(int x, int y){
  int px = find_set(x);
  int py = find_set(y);
  if(px == py){
    return;
  }
  F[px] = py;
}

void union_enemy(int x, int y){
  int px = find_set(x);
  int py = find_set(y);
  if(px == py){
    return;
  }
  E[py]|=E[px];
  E[px] = E[py];
}

void init(int N){
  for(int i=0; i<N; i++){
    F[i] = i;
    E[i].reset();
  }
}


void solver(int c, int x, int y){
  int fx = find_set(x);
  int fy = find_set(y);
  switch (c) {
    case 1:
    {
      if(fx != fy){
        if(E[fx].test(fy) || E[fy].test(fx)){
            cout << "-1" << endl;
          }else{
            union_set(fx, fy);
            union_enemy(fx,fy);
          }
      }
    }
      break;
    case 2:
    {
      if(fx != fy){
        E[fx].set(fy);
        E[fy].set(fx);
      }else{
        cout<< "-1" << endl;
      }
    }
      break;
    case 3:
    {
      if(fx == fy){
        cout<< "1" <<endl;
        break;
      }
      if((E[fx]&E[fy]).any()){
        cout << "1" << endl;
        union_set(fx, fy);
        union_enemy(fx,fy);
      }else{
        cout << "0" << endl;
      }
    }
      break;
  case 4:
  {
      if(E[fx].test(fy) || E[fx].test(fy)){
        cout << "1" << endl;
      }else{
        cout << "0" << endl;
        union_set(fx, fy);
        union_enemy(fx,fy);
      }
    }
      break;
  }
}
/* Verificar los papas siempre */



int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, q, x, c, y;
  while(cin >> n >> q){
    init(n);
    for(int i=0; i<q; i++){
      cin >> c >> x >> y;
      solver(c,x,y);
    }
  }
  return 0;
}
