#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int binarySearch(vector<int> S, int key){
    int right = S.size();
    int left = 0;
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if(S[mid]<key){
            left = mid+1;
        }else
        {
            right = mid;
        }
    }
    return left;
}

int LongestIncreasingSubsequence(vector<int> vec){
    int n = vec.size();
    vector<int> lis(n, INF);
    for (int i=0;i<n;i++){
        int idx = binarySearch(lis,vec[i]);
        lis[idx] = vec[i];
    }
    
    int mx;
    for (int i=0;i<n;i++){
        if (lis[i] == INF)break;
        mx = i+1;
    }
    return mx;
}

int main(){
    vector<int> vec{1,3,2,6,9,8,10,7};
    cout << LongestIncreasingSubsequence(vec) << endl;
}