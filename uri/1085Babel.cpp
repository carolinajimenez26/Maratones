//https://www.urionlinejudge.com.br/judge/es/problems/view/1085

#include <bits/stdc++.h>
using namespace std;


int Dijsktra(string source, string target, map<string, vector< pair< string, pair <int, string > > > > &G,
              map<string,bool> &visited, map<string,int> &dist){

  dist[source] = 0;
  priority_queue< pair<int, pair<string, string> >, vector< pair<int, pair<string, string> > >, greater< pair<int, pair<string, string> > > > pq;
  pq.push(make_pair(0,make_pair(source,"")));

  while(!pq.empty()){
    string v = pq.top().second.first;
    int w = pq.top().first;//cantidad de letras de la palabra
    string word = pq.top().second.second;//palabra

    pq.pop();
    if(v == target)
      return w;

    if(visited[v])
      continue;
    visited[v] = true;

    for(int i = 0; i < G[v].size(); i++){
      string nv = G[v][i].first;//lenguaje
      int nw = G[v][i].second.first;//cantidad de letras de la palabra
      string nword = G[v][i].second.second;//palabra
      if(!visited[nv]){
        int new_w = w + nw;
        if(new_w <= dist[nv] && word[0] != nword[0]){
          dist[nv] = new_w;
          pq.push(make_pair(new_w,make_pair(nv,nword)));
        }
      }
    }
  }
  return -1;//si no hay camino
}

bool comp(const pair< string, pair <int, string>> &a,
                                  const pair< string, pair <int, string>> &b) {

    if (a.second.first == b.second.first) {
      return a.second.second > b.second.second;
    } else {
      return a.second.first > b.second.first;
    }
}

int main(void){

  while(true){//cuando M es cero se sale
    map<string, vector< pair< string, pair <int, string > > > > G;
    map<string, bool> visited;
    map<string, int> dist;
    int M;
    cin >> M;
    if(M == 0) break;

    string O, D; //origen, destino
    cin >> O >> D;
    for(int i = 0; i < M; i++){//Construimos el grafo
      string O_aux, D_aux, word;
      cin >> O_aux >> D_aux >> word;
      visited[O_aux] = false;
      visited[D_aux] = false;
      dist[O_aux] = numeric_limits<int>::max();
      dist[D_aux] = numeric_limits<int>::max();
      //Grafo bi-dirigido

      //Agregamos palabras compartidas en ambos lenguajes
      G[O_aux].push_back(make_pair(D_aux,make_pair(word.length(),word)));
      G[D_aux].push_back(make_pair(O_aux,make_pair(word.length(),word)));
    }

      int ans = Dijsktra(D,O,G,visited, dist);
      if(ans == -1) cout << "impossivel" << endl;
      else cout << ans << endl;


  }

  return 0;
}
