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
const int INTINF = 1<<30;
const ll LLINF = 1LL<<62;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const int DX[8]={ 0, 1, 0,-1, 1, 1,-1,-1};
const int DY[8]={ 1, 0,-1, 0, 1,-1, 1,-1};




bool BinarySearch(vector<int> S, int key){
    int right = S.size();
    int left = 0;
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if (S[mid] == key){
            return true;
        }else if(S[mid]<key){
            left = mid+1;
        }else
        {
            right = mid;
        }
    }
    return false;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> vec = {1,3,5,7,9};
  REP(i,10)cout << BinarySearch(vec, i) << endl;
}
