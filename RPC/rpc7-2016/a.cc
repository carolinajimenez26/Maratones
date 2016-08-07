#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100000 + 10
#define VMAX numeric_limits<ld>::max()
#define VMIN numeric_limits<ld>::min()
#define ld long double
ld cheetahs[MAX]; //velocidad de cada cheetah
ld tcheetahs[MAX]; //tiempo de salida de cada cheetah
int N;
ld tup = 1e8; //suposición tiempo máximo
ld tdown;//tiempo en el que sale el último cheetah
ld EPS = 1e-9; //error de precisión

ld diff(ld t){
  ld d_max = VMIN, d_min = VMAX ;
  for(int i = 0; i < N; i++){
    d_max = max(d_max, (t - tcheetahs[i])*cheetahs[i]);
    d_min = min(d_min, (t - tcheetahs[i])*cheetahs[i]);
  }
  return d_max - d_min;
}

ld solver(){
  tup = 1e8 + tdown;
  ld t1, t2, d1, d2;
  int step = int(tdown); //se empieza desde que sale el último cheetah
  int maxiter = 1e8 + tdown; //máximas iteraciones
  for(; step < maxiter; step++){
    t1 = (2.0*tdown + tup)/3.0;
    t2 = (tdown + 2.0*tup)/3.0;
    //if(!(t1 <= t2 + EPS && t1 + EPS < t2)) break;
    if( t2 - t1 <= EPS) break;
    d1 = diff(t1);
    d2 = diff(t2);
    //cout<<"d1: "<<d1<< "d2: " <<d2 << endl << " t1: " << t1 << " t2: " << t2 <<endl;
    //cout << "step : " << step << endl;
    if( d1 <= d2)
      tup = t2;
    else
      tdown = t1;
  }
  return diff((t1+t2)*0.5);
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ld t,v, ans;
  while(cin>>N && N!=0){
    //cout<<N<<endl;
    //cin>>N;
    tdown = VMIN;
    for(int i=0; i< N; i++){
      cin >> tcheetahs[i] >> cheetahs[i];
      tdown = max(tdown, tcheetahs[i]);
    }
    ans = solver();
    cout << fixed << setprecision(3) << ans << endl;
  }
  return 0;
}
