#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1004
char f1[MAX][MAX], f2[MAX][MAX], f3[MAX][MAX];

vector<string> convertLine(string line){
  vector<string> v;
  stringstream ss(line);
  string tok;
  while(ss>>tok){
    v.push_back(tok);
  }
  return v;
}

int str2int(string s){
  int num;
  stringstream ss;
  ss << s;
  ss >> num;
  return  num;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int N,M;
  string cad, line;
  char falcon, c;
  while(getline(cin, line)){
    vector<string> tokens = convertLine(line);
    N = str2int(tokens[0]);
    M = str2int(tokens[1]);
    if(tokens.size() == 4 && N ==0 && M == 0) break;
    //cout<<N<<" "<<M<<" "<<c<<endl;
    queue<pair<int, int> > q;

    falcon = tokens[2][1];
    pair<int, int> p1, p2; // posicion f1 y f2
    int cont = 0;
    //leer f1
    for(int i=0; i<N; i++){
      getline(cin,line);
      for(int j=0; j<M; j++){
        c = line[j];
        if(c == falcon){
          if(cont == 0)
            p1 = make_pair(i,j);
          cont++;
        }else{
          f3[i][j] = c;
        }
      }
    }
    getline(cin, line);
    // leer f2
    cont = 0;
    for(int i=0; i<N; i++){
      getline(cin, line);
      for(int j=0; j<M; j++){
        c = line[j];
        if(c == falcon){
          if(cont == 0)
            p2 = make_pair(i,j);
          q.push(make_pair(i,j));
          cont++;
        }else{
          f3[i][j] = c;
        }
      }
    }
    getline(cin, line);
    //calcular dy y dx, positivo en dy movimiento derecha
    // positivo dx movimiento hacia abajo
    int dx = p2.first - p1.first, dy = p2.second - p1.second;
    while(!q.empty()){
      pair<int, int> p = q.front();
      q.pop();
      p.first += dx;
      p.second += dy;
      if(p.first>= 0 && p.first < N && p.second >= 0 && p.second < M ){
        f3[p.first][p.second] = falcon;
      }
    }

    for(int i=0; i<N; i++){
      for(int j=0; j< M; j++){
        cout<<f3[i][j];
      }
      cout<<endl;
    }
    cout<<endl;

  }


  return 0;
}
