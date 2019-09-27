#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define SUM(a)  accumulate((a).begin(),(a).end(),0)
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
typedef long long ll;
const int INF = 999999999;
const int MOD = (int)1e9 + 7;
const int EPS = 1e-9;

vector<int> Eratosthenes(int n){
  bool dp[n+1];
  REP(i,n+1)dp[i]=false;
  dp[0] = dp[1] = true;
  vector<int> prime;
  FOR(i,2,n+1){
    if(!dp[i]){
      prime.push_back(i);
      for (int j = i*2; j<n+1 ; j+=i)dp[j] = true;
    }
  }
  return prime;
}

bool PrimeNumber(int n){
  vector<int> prime = Eratosthenes(n);
  return n==prime.back();
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cout << PrimeNumber(n) << endl;
}