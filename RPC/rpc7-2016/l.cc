#include <bits/stdc++.h>
using namespace std;
#define ll int
ll _sieve_size;
bitset<9999999> bs;
vector<int> primes;

void sieve(ll upperbound){
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i = 2; i < _sieve_size; i++) if(bs[i]){
      for(ll j=i*i; j<= _sieve_size; j+= i) bs[j] = 0;
      primes.push_back((int)i);
    }

}

bool isPrime(ll N){
  if(N <= _sieve_size) return bs[N];
  for(int i=0; i< (int)primes.size(); i++)
    if( N% primes[i] == 0) return false;

  return true;
}

ll string2long(string s){
  ll num;
  stringstream ss;
  ss << s;
  ss >> num;
  return num;
}

int gcd(int a, int b){
  int tmp;
  while(b){
    a %= b;
    tmp = a;
    a = b;
    b = tmp;
  }
  return a;
}

int main(){
  string s, s1, s2;
  int N, l;
  ll n1,n2;
  bool flag = false;
  cin>>N;
  for(int i=0; i<N; i++){
    cin>>s;
    l = s.size();
    flag = false;
    cout<<"Ticket #"<<i+1<<":"<<endl;
    for(int j=1; j< l; j++){
      s1 = s.substr(0,j);
      s2 = s.substr(j,l);
      n1 = string2long(s1);
      n2 = string2long(s2);
      if( isPrime(n1) && isPrime(n2) && gcd(n1,n2) == 1){
        cout<<n1<<" "<<n2<<endl;
        flag = true;
        break;
      }
    }
    if(!flag){
      cout<<"Not relative"<<endl;
    }
  }
  return 0;
}
