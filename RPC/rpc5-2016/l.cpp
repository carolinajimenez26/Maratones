#include<bits/stdc++.h>

using namespace std;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

struct state{
  int x,y,z,d;
  state() {x = y = z = d = 0;}
  state(int _x, int _y, int _z, int _d) :  x(_x), y(_y), z(_z), d(_d) {}
};
int h, w, l;
// l -> # de rows, w -> # de cols, h -> # de floors
char maze[105][105][105];
bool vi[105][105][105];

int BFS(state s, state e){
  queue<state> q;
  q.push(s);
  vi[s.x][s.y][s.z] = 1;

  while(!q.empty()){
    state act = q.front();
    q.pop();
    //cout<<act.x<<","<<act.y<<","<<act.z<<","<<act.d<<endl;
    if(maze[act.x][act.y][act.z] == 'E'){ return act.d; }

    for(int i=0; i<4;i++){
      int x,y;
      x = act.x + dx[i];
      y = act.y + dy[i];
      if(x>=0 && x<l && y>=0 && y<w && !vi[x][y][act.z]){
        if((maze[x][y][act.z]=='.'|| maze[x][y][act.z]=='-' || maze[x][y][act.z]=='E') && !vi[x][y][act.z]){ // Que hago si no es un ascenso ingresar a las colas norma las posiciones validas
          state vl(x,y,act.z,act.d+1);
          q.push(vl);
          vi[vl.x][vl.y][vl.z] = 1;
        }
      }
    }
    if(maze[act.x][act.y][act.z]=='-'){
      int down = act.z+1, up=act.z-1;
      if(down >= 0 && down < h && !vi[act.x][act.y][down]){
        state nd(act.x,act.y,down,act.d+1);
        if(maze[act.x][act.y][down]=='-' && !vi[act.x][act.y][down]){
          q.push(nd);
          vi[nd.x][nd.y][nd.z] = 1;
        }
      }
      if(up >= 0 && up < h && !vi[act.x][act.y][up]){
        state nu(act.x,act.y,up,act.d+1);
        if(maze[act.x][act.y][up]=='-' && !vi[act.x][act.y][up]){
          q.push(nu);
          vi[nu.x][nu.y][nu.z] = 1;
        }
      }
    }

  }
  return -1;
}

int main(){
  state s, e;
  while(cin >> l >> w >> h){
    memset(vi, 0, sizeof(vi));
    if(h==0 and w==0 and l==0) break;
    for(int i=0; i<h; i++){
      for(int j=0; j< l; j++)
        for(int t=0; t< w ; t++){
          cin>>maze[j][t][i];
          if(maze[j][t][i] == 'S'){
            state source(j,t,i,0);
            s = source;
          }
          if(maze[j][t][i] == 'E'){
            state target(j,t,i,0);
            e = target;
          }
        }
    }
    //cout<<s.x<<","<<s.y<<":"<<s.z<<endl;
    //cout<<e.x<<","<<e.y<<":"<<e.z<<endl;
    cout<<BFS(s, e)<<endl;
    }



}
