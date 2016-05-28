#include <bits/stdc++.h>
using namespace std;
char S[100010];
int seen[27];
int value[27];

void init(){
  for (int i=1; i<= 26; i++){
    value[i] = i;
  }
  value[2] = 5;
  value[5] = 2;
  value[6] = 9;
  value[9] = 6;
  value[12] = 15;
  value[15] = 12;
  value[16] = 19;
  value[19] = 16;
  value[20] = 50;
  value[21] = 51;
  value[22] = 55;
  value[23] = 53;
  value[24] = 54;
  value[25] = 52;
  value[26] = 59;

}
int main(){
  init();
  while(cin>>S){
    memset(seen,-1, sizeof seen);
    int len = strlen(S);
    int cont=1;
    for(int i=0;i< len;i++){
      if(seen[S[i]-96]!=-1)
        printf("%d",value[seen[S[i]-96]]);
      else{
        seen[S[i]-96] = cont++;
        printf("%d",value[seen[S[i]-96]]);
      }
    }
    printf("\n");
  }
  return 0;
}
