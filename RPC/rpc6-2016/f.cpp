#include <bits/stdc++.h>
using namespace std;
#define inf numeric_limits<long long>::max()/2
#define MAX 2700
#define endl '\n'

unordered_map<string,long long> id;
long long GW[MAX][MAX];
vector<long long> G[MAX];
bool visitados[MAX];
long long p[MAX];
bool fct[MAX];
bool smn[MAX];
bool tran[MAX];
bool tranp[MAX];
long long s,r,f,t;

void init(){
    long long limit = s + 2*t + 1;
    for(long long i=0; i<= limit ;i++)
        visitados[i] = false;
}

bool bfs(long long source, long long target){//says if there are a path form source to target
  stack<long long> st;
  visitados[source] = true;
  st.push(source);
  p[source] = -1;
  while(!st.empty()){
    long long v = st.top();
    st.pop();
    if(v == target) return true; //there is a path
    for(long long i = 0; i < G[v].size(); i++){
      long long nv = G[v][i];
      long long nw = GW[v][nv];
      if(!visitados[nv] && nw > 0){
        visitados[nv] = true;
        st.push(nv);
        p[nv] = v; //the father of nv is v
      }
    }
  }
  return false;//there is no path
}

pair<long long, vector<long long> > minWeight(long long target){
  long long p1 = p[target];
  long long w = inf;
  vector<long long> path;
  path.push_back(target);
  while(p1 != -1){
    long long nw = GW[p1][target];
    //cout << "p1 : " << p1 << " target : " << target << " nw : " << nw << endl;
    w = min(w,nw);
    path.push_back(p1);
    target = p1;
    p1 = p[p1];
  }
  return make_pair(w,path);
}

long long FF(long long source, long long target){//Ford-Fulkerson
  long long maxf = 0;
  while(bfs(source, target)){
    //cout<<"Encontre un camino"<<endl;
    pair<long long, vector<long long> > mw = minWeight(target);//get the min weight and the path
    //prlong longgraph();
    //cout<<"Camino: "<<"Size(): "<<mw.second.size()<<endl;
    //prlong longpath(mw.second);
    //cout<<"|"<<flag<<" min: "<<mw.first<<endl;

    maxf += mw.first;
    //cout << endl << mw.first << endl;
    for(long long i = 0; i < mw.second.size() - 1; i++){
      GW[mw.second[i]][mw.second[i+1]] += mw.first;
      GW[mw.second[i+1]][mw.second[i]] -= mw.first;
    }
    init();
    //iter++;
  }
  return maxf;
}

string int2string(int x){
  stringstream ss;
  ss << x;
  string str = ss.str();
  return str;
}


int get_id(string &line) {
  if (id.count(line))
    return id[line];
  int ans = id.size();
  return id[line] = ans;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  memset(GW,0,sizeof GW);
  memset(smn,0,sizeof smn);
  memset(fct,0,sizeof fct);
  memset(tran,0,sizeof tran);
  memset(tranp,0,sizeof tranp);
  int tt,cont=1, source, target;
  string  _c,_s,_f;
  cin>>s>>r>>f>>t;
  source = s + t + t;
  target = source + 1;
  //supliers
  for(int i=0; i<r;i++){
    cin>>_s;
    G[source].push_back(get_id(_s));
    G[get_id(_s)].push_back(source);
    GW[source][get_id(_s)] = 1;
    GW[get_id(_s)][source] = 0;
    //smn[CC[_s]] = 1;
  }
  //factories
  for(int i=0; i<f;i++){
    cin>>_f;
    G[target].push_back(get_id(_f));
    G[get_id(_f)].push_back(target);
    GW[target][get_id(_f)] = 0;
    GW[get_id(_f)][target] = 1;
    //fct[CC[_f]] = 1;
  }
  int trp, trpp;
  for(int i=0;i<t;i++){
    cin>>tt;
    trp = (i << 1) + s,
    trpp = (i << 1 | 1) + s;
    G[trp].push_back(trpp);
    G[trpp].push_back(trp);
    GW[trp][trpp] = 1;
    GW[trpp][trp] = 0;
    //tran[trp] = 1;
    //tranp[trpp] = 1;
    for(int j=0;j<tt;j++){
      cin >> _c;
      G[get_id(_c)].push_back(trp);
      G[trp].push_back(get_id(_c));
      GW[get_id(_c)][trp] = 1;
      GW[trp][get_id(_c)] = 0;
      G[trpp].push_back(get_id(_c));
      G[get_id(_c)].push_back(trpp);
      GW[get_id(_c)][trpp] = 0;
      GW[trpp][get_id(_c)] = 1;
      /*
      if(smn[CC[_c]]){
        G[CC[_c]].push_back(trp);
        G[trp].push_back(CC[_c]);
        GW[CC[_c]][trp] = 1;
        GW[trp][CC[_c]] = 0;
      }else if(fct[CC[_c]]){
        G[CC[_c]].push_back(trpp);
        G[trpp].push_back(CC[_c]);
        GW[CC[_c]][trpp] = 0;
        GW[trpp][CC[_c]] = 1;
      }else{
        G[CC[_c]].push_back(trp);
        G[trp].push_back(CC[_c]);
        GW[CC[_c]][trp] = 1;
        GW[trp][CC[_c]] = 0;
      }
      */
    }
  }

  cout << FF(source, target) << endl;


  return 0;
}
