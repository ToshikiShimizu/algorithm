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
const int INTINF = 1<<29;
const ll LLINF = 1LL<<61;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const int DX[8]={ 0, 1, 0,-1, 1, 1,-1,-1};
const int DY[8]={ 1, 0,-1, 0, 1,-1, 1,-1};

vector<int> A = {4,8,1,2,0,6,5,7,9,3};

int Partition(int p, int r){
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++){
    if (A[j] <= x){
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[r]);
  return i+1;
}

void QuickSort(int left, int right){
  if (left < right){
    int st = Partition(left, right);
    QuickSort(left, st-1);
    QuickSort(st+1,right);
  }
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  QuickSort(0,A.size()-1);
  for (auto x: A){
    cout << x << " ";
  }
  cout << endl;
}
