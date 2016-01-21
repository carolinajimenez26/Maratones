//https://www.urionlinejudge.com.br/judge/es/problems/view/1945
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int tonum(string &s){
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

vector<string> split(string &s){
  stringstream ss;
  ss << s;

  vector<string> v;
  string tok;
  while(ss >> tok){
    v.push_back(tok);
  }
  return v;
}

bool isDigit(char c){
  return (int)c >= 48 && (int)c <= 57;
}

int main(void){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string input,var;
  map<string, int> mapa;//variable con su asignación
  int val, val2;

  while(getline(cin, input)){

    vector<string> split_input = split(input);

    //Se cumple siempre
    var = split_input[0];

    if(split_input.size() == 3){//asignación
        if(isDigit(split_input[2][0]))
          val = tonum(split_input[2]);
        else val = mapa[split_input[2]];

        mapa[var] = val;
    }else{//asignación con suma

      if(isDigit(split_input[4][0]))
        val2 = tonum(split_input[4]);
      else val2 = mapa[split_input[4]];

      if(isDigit(split_input[2][0]))
        val = tonum(split_input[2]);
      else
        val = mapa[split_input[2]];

      mapa[var] = val + val2;
    }
  }
  cout << mapa[var] << endl;
  //for(pair<string,int> x : mapa)
    //cout << x.first << " : " << x.second <<endl;

  return 0;
}
