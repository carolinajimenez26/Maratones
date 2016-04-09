//http://www.lightoj.com/volume_showproblem.php?problem=1238
//1238 - Power Puff Girls
#include <bits/stdc++.h>
using namespace std;
int city[4][20];//máximo número de casillas
bool visited[4][20];
//N,O,S,E
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

int bfs(pair<int, int> source, pair<int, int> target, int M, int N){
  queue<pair<int, int> > q;//cola de coordenadas
  q.push(source);
  map<pair<int,int>, pair<int,int> > parents; // llave: hijo, valor:papa
  parents[source] = make_pair(-1,-1);
  while(!q.empty()){
    pair<int, int > n = q.front();//nodo en el que nos paramos
    q.pop();//lo sacamos de la cola
    if(n == target) break;//retorna la cantidad de movimientos que tuvo

    for(int i = 0; i < 4; i++){//4 movimientos válidos
      pair<int, int> nv = make_pair(n.first + dx[i] , n.second + dy[i]);//se para en alguna de sus posibilidades
      if(nv.first >= 0 && nv.first < N && nv.second >= 0 && nv.second < M){//si no se sale de las dimensiones de la matriz
        if(!visited[nv.first][nv.second] && city[nv.first][nv.second] != '#' && city[nv.first][nv.second] != 'm'){//si no es un monstruo o pared
          q.push(nv);//posición válida
          visited[nv.first][nv.second] = true;//visitada
          parents[nv] = n;
        }
      }
    }
  }

  //Contar movimientos
  int moves = 0;
  pair<int,int> p = target;
  while(p.first!=-1 && p.second!=-1){
    moves++;
    p = parents[p];
  }
  return moves;
}


int main(void){
  int T;//casos
  cin >> T;
  int cases = 1;
  while(T--){
    int m, n;//dimensiones de la matriz
    int ans1, ans2, ans3;//respuestas
    pair<int, int> a,b,c,h;//coordenadas de las chicas y casa
    cin >> m >> n;

    char e;//caracter
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cin >> e;
        if(e = 'a') a = make_pair(i,j);
        if(e = 'b') b = make_pair(i,j);
        if(e = 'c') c = make_pair(i,j);
        if(e = 'h') h = make_pair(i,j);
        city[i][j] = e;
        visited[i][j] = false;
      }
    }

    ans1 = bfs(a,h,m,n);
    ans2 = bfs(b,h,m,n);
    ans3 = bfs(c,h,m,n);

    //en ans1 va a quedar la respuesta mayor
    int ans = max(ans1, max(ans2,ans3));

    cout << "Case " << cases << ": " << ans << endl;
    cases++;
  }
  return 0;
}
