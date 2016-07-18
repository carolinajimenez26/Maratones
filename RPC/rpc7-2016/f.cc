#include <bits/stdc++.h>
using namespace std;
#define MAX 5005
#define endl '\n'
vector< pair<unsigned long long int, unsigned long long int> > s1(MAX), s2(MAX);
vector<unsigned long long int> oS2(MAX); // s2 ordenado, solo los valores no freciencias
vector<unsigned long long int> fS2(MAX); // s2 ordenado, frecuencias
unsigned long long int vs[MAX], vm[MAX], vd[MAX], vb[MAX];
unsigned long long int L,S,M,D,B;

vector<unsigned long long int> splitLine(string line){
  vector<unsigned long long int> v;
  stringstream ss(line);
  unsigned long long int tok;
  while(ss>>tok){
    v.push_back(tok);
  }
  return v;
}

unsigned long long int build(vector<unsigned long long int> &tmpA, vector<unsigned long long int> &tmpB, bool flag){
  unsigned long long int lA = tmpA.size(), lB = tmpB.size(), tmp, idx=0;
  unordered_map<unsigned long long int, unsigned long long int> id;

  for(unsigned long long int i=0; i<lA; i++){
    for(unsigned long long int j=0; j<lB; j++){
      tmp = tmpA[i] + tmpB[j];
      if(tmp < L){
        if(!id.count(tmp)){
          id[tmp] = idx;
          idx += 1;
          if(!flag)
            s1[id[tmp]] = make_pair(tmp,1);
          else
            s2[id[tmp]] = make_pair(tmp,1);
        }else{
          if(!flag)
            s1[id[tmp]].second+= 1;
          else
            s2[id[tmp]].second+= 1;
        }
      }
    }
  }

  return idx;
}

void splitS2(unsigned long long int sizeS2){
  unsigned long long int tmp = 0;
  for(unsigned long long int i=0; i<sizeS2; i++){
    oS2[i] = s2[i].first; //Valor
    tmp += s2[i].second;  // frecuencia acumulada
    fS2[i] = tmp;
    //cout<<"oS2: "<<oS2[i]<<" fS2: "<<fS2[i]<<endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  //cout<<"inicio"<<endl;
  while(true){
    fill(oS2.begin(), oS2.end(), 0); // s2 ordenado, solo los valores no freciencias
    fill(fS2.begin(), fS2.end(), 0); // s2 ordenado, frecuencias
    memset(vs, 0, sizeof vs);
    memset(vm, 0, sizeof vm);
    memset(vd, 0, sizeof vd);
    memset(vb, 0, sizeof vb);

    string line;
    vector<unsigned long long int> nums, tmpA, tmpB;
    unsigned long long int cont=0;
    //cout<<"hola mundo"<<endl;
    cont = 0;
    getline(cin, line);
    nums = splitLine(line);
    L = nums[0], S = nums[1], M = nums[2], D = nums[3], B = nums[4];
    if(L==0 && S==0 && M==0 && D==0 && B==0) break;
    //cout<<"hola"<<endl;
    // S
    getline(cin,line);
    tmpA = splitLine(line);
    // M
    getline(cin,line);
    tmpB = splitLine(line);
    // ORGNIZAR PARA GUARDAR SOLO LOS VALORES QUE SON MENORES A L
    unsigned long long int sizeS1 = build(tmpA,tmpB,0);
    //cout<<"sizeS1: "<<sizeS1<<endl;
    // D
    getline(cin,line);
    tmpA = splitLine(line);
    // B
    getline(cin,line);
    tmpB = splitLine(line);
    unsigned long long int sizeS2 = build(tmpA,tmpB,1);
    //cout<<"sizeS12 "<<sizeS2<<endl;
    sort(s2.begin(), s2.begin() + sizeS2);
    splitS2(sizeS2);

    // Comparar vector ordenado con desordenado
    unsigned long long int rest, idx;
    vector<unsigned long long int>::iterator low;
    for(unsigned long long int i=0; i<sizeS1; i++){
      rest = L - s1[i].first;
      low = lower_bound (oS2.begin(), oS2.begin() + sizeS2, rest); //
      idx = low - oS2.begin();
      if(*low == rest){
        cont += s1[i].second*fS2[idx];
      }else if(idx - 1 >= 0 && oS2[idx - 1] < rest){
        cont += s1[i].second*fS2[idx - 1];
      }
    }
    cout<<cont<<endl;
    getline(cin, line);
  }
  return 0;
}
