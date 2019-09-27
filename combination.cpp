#include<bits/stdc++.h>
using namespace std;
static const int MOD = 1000000007;
int Combination(int n, int r){
  vector<vector<long long> > dp(n+1,vector<long long>(n+1));
  for (int i=0;i<=n;i++){
    dp[i][0] = 1;
    dp[i][i] = 1;
  }
  for (int i=1;i<=n;i++)
    for (int j=1;j<i;j++)
      dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
  return dp[n][r];
}

int CombinationFast(int n, int r){
  if (n/2<r)r=n-r;
  vector<vector<long long> > dp(n+1,vector<long long>(r+1));
  for (int i=0;i<=n;i++){
    dp[i][0] = 1;
  }
  for (int i=0;i<=r;i++){
    dp[i][i] = 1;
  }
  for (int i=1;i<=n;i++)
    for (int j=1;j<i && j<=r;j++)
      dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%MOD;
  return dp[n][r];
}

int main(){
  int n,r;
  cin >> n >> r;
  cout << Combination(n,r) << endl;
}

