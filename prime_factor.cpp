#include<bits/stdc++.h>
using namespace std;
map<long long, int> PrimeFactor(int n){ // O(sqrt(n))
  map<long long, int> ret;
  for (int i=2;i*i<=n;i++){
    while(n%i==0){
      ret[i]++;
      n/=i;
    }
  }
  if (n!=1){
    ret[n] = 1;
  }
  return ret;
}

int main() {
  int N;
  cin >> N;
  for(auto p : PrimeFactor(N)) {
  cout << p.first << " " << p.second << endl;
  }
}