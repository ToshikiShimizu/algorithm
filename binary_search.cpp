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

bool CheckLowerBoundArray(int index, int key) {
    return v[index] >= key;
}

bool CheckUpperBoundArray(int index, int key) {
    return v[index] > key;
}

int BinarySearch(int key, int left, int right){
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (CheckLowerBoundArray(mid, key)) right = mid; // 任意の関数を設定可能
        else left = mid;
    }
    return right; //lower_bound
}

// BinarySearchにCheckLowerBoundArrayなど"="も真とする関数を設定する必要がある
bool Contain(int key, int left, int right){ 
    int lb = BinarySearch(key,left,right);
    return v[lb]==key; 
}

int main() {
    dump(BinarySearch(1,-1,v.size()));// key, min-1, max+1
    dump(BinarySearch(2,-1,v.size()));
    dump(BinarySearch(3,-1,v.size()));
    dump(BinarySearch(9,-1,v.size()));
    dump(BinarySearch(100,-1,v.size()));
    dump(Contain(1,-1,v.size()));
    dump(Contain(2,-1,v.size()));
    dump(Contain(3,-1,v.size()));
    dump(Contain(4,-1,v.size()));
}