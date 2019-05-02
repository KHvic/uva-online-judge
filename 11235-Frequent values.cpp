#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100000;

int segment[2*SIZE];
int value[SIZE];
unordered_map<int,int> start;
unordered_map<int,int> cnt;
// short implementation of segment tree O(logN) query
int query(int l, int r, int n){
    int res = 0;
    for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
        if(l&1) res = max(res,segment[l++]);
        if((r&1) == 0) res = max(res,segment[r--]);
    }
    return res;
}

int main() {
    int n,q,v;
    int l,r;
    while(scanf("%d",&n),n){
        start.clear();
        cnt.clear();
        cin >> q;
        for(int i=0;i<n;i++){
            cin >> v;
            value[i] = v;
            if(++cnt[v] == 1) start[v] = i;
        }
        // build child
        for(int i=0;i<n;i++) segment[n+i] = cnt[value[i]];
        // build parent
        for(int i=n-1;i>0;i--) segment[i] = max(segment[i*2],segment[i*2+1]);
        // query
        for(int i=0;i<q;i++){
            cin >> l >> r;
            l--; r--;
            if(value[l] == value[r]){
                // same value, take R-L+1
                cout << r-l+1 << endl;
            } else {
                // find next number pos from left
                int leftVal = value[l], rightVal = value[r];
                int nextNumPos = start[leftVal] + cnt[leftVal];
                int leftCount = nextNumPos - l;
                int rightCount = r - start[rightVal] + 1;
                // find middle best result using segment tree
                int middleCount = query(nextNumPos, start[rightVal]-1, n);
                cout << max(max(leftCount, rightCount), middleCount) << endl;
            }
        }
    }
}
