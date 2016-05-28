#include <bits/stdc++.h>
using namespace std;

list<int> l;
list<int>::iterator it;
int m;

void init(){
  l.clear();
  for(int i=1;i<=100;i++)
    l.push_back(i);
}

int josephus(int k, int t){
  init();
  it = l.begin();
  while(l.size() > 1){
    switch (t) {
      case 1: for(int i=0; i<k-1; i++){
                it++;
                if(it == l.end()){
                  it = l.begin();
                }
              }
              if(*it == m ) return 0;
              it = l.erase(it);
              if(it == l.end()){
                it = l.begin();
              }
              t = 2;
              break;

      case 2: for(int i=0; i<k-1; i++){
                      if(it == l.begin()){
                        it = l.end();
                      }
                      it--;
                    }
                    if(*it == m) return 0;
                    it = l.erase(it);
                    if(it == l.begin()){
                      it = l.end();
                    }
                    it--;
                    t = 1;
                    break;
     }
  }
  return *l.begin();
}

int main(){
  while(cin >> m && m!=0){
    l.clear();
    for(int i=1; i<=1000; i++){
      if(josephus(i,1) == m){
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
