#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

int F[MAX];
unordered_map<int, set<int> > E;

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
  set<int> ex = E[px];
  set<int> ey = E[py];
  set<int>::iterator it;
  for(it=E[px].begin(); it!=E[px].end(); ++it){
    E[py].insert(*it);
  }
  E[px] = E[py];
}

void init(int N){
  set<int> emptyset;
  for(int i=0; i<N; i++){
    F[i] = i;  // TENER EN CUENTA REPRESENTAR ENEMIGO MI MISMP
    //E[i] = new set<int>();
    E[i] = emptyset;
  }
}


void solver(int c, int x, int y){
  switch (c) {
    case 1:
    {
    // if(E[F[x]] != E[F[y]])
    if(E[find_set(x)].count(find_set(y)) || E[find_set(y)].count(find_set(x))){
        cout << "-1" << endl;
      }else{
        union_set(x, y);
        union_enemy(x,y);
      }
    }
      break;
    case 2:
    {
      if(find_set(x) != find_set(y)){
        //E[F[x]] = F[y];
        E[find_set(x)].insert(find_set(y));
        //F[y] = E[F[x]];
        E[find_set(y)].insert(find_set(x));
      }else{
        cout<< "-1" << endl;
      }
    }
      break;
    case 3:
    {
      if(find_set(x) == find_set(y)){
        cout<< "1" <<endl;
        break;
      }
      set<int> myset_tmp;
      set<int>::iterator it;
      if(E[find_set(x)].size()>E[find_set(y)].size()){
        myset_tmp = E[find_set(x)];
        for(it=E[find_set(y)].begin(); it!=E[find_set(y)].end(); ++it){
          myset_tmp.insert(*it);
        }
      }else{
        myset_tmp = E[find_set(y)];
        for(it=E[find_set(x)].begin(); it!=E[find_set(x)].end(); ++it){
          myset_tmp.insert(*it);
        }
      }
      //cout<<"myset: "<<myset_tmp.size()<<" suma: "<<E[find_set(x)].size() + E[find_set(y)].size()<<" ";
      if(myset_tmp.size() == (E[find_set(x)].size() + E[find_set(y)].size()) ){
        cout << "0" << endl;
      }else{
        cout << "1" << endl;
        union_set(x, y);
        union_enemy(x,y);
      }
    }
      break;
  case 4:
  {
      if(E[find_set(x)].count(find_set(y)) != 0 || E[find_set(y)].count(find_set(x)) != 0 ){
        cout << "1" << endl;
      }else{
        cout << "0" << endl;
        union_set(x, y);
        union_enemy(x,y);
      }
    }
      break;
  }
}
/* Verificar los papas siempre */



int main(){
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
