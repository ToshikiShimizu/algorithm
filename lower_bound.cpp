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

vector<int> v = {2, 2, 5, 5, 9, 9, 9, 10, 11};

bool check(int index, int key) {
    return v[index] >= key;
}

int LowerBound(int key, int left, int right){
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (check(mid, key)) right = mid;
        else left = mid;
    }
    return right; //lower_bound
}

bool Contain(int key, int left, int right){
    int lb = LowerBound(key,left,right);
    return v[lb]==key; 
}

int main() {
    dump(LowerBound(1,-1,v.size()));// key, min-1, max+1
    dump(LowerBound(2,-1,v.size()));
    dump(LowerBound(3,-1,v.size()));
    dump(LowerBound(9,-1,v.size()));
    dump(LowerBound(100,-1,v.size()));
    dump(Contain(1,-1,v.size()));
    dump(Contain(2,-1,v.size()));
    dump(Contain(3,-1,v.size()));
    dump(Contain(4,-1,v.size()));
}