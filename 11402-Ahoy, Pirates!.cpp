#include <bits/stdc++.h>
using namespace std;

int segment[1024000*3]; // sum segment
int lazy[1024000*3]; // store ops
char str[1050000];

void build(int idx, int low, int high){
    lazy[idx] = 0;
    if(low > high) return;
    if(low == high) {
        segment[idx] = str[low] - '0';
        return;
    }
    int mid = (low+high)/2;
    build(idx*2+1, low, mid);
    build(idx*2+2, mid+1, high);
    segment[idx] = segment[idx*2+1] + segment[idx*2+2];
}

// combine old operation with new operation to new op
int combineOp(int prevOp, int curOp){
    // 1 and 2 has highest precedence overwrite
    if(curOp == 1) return 1;
    if(curOp == 2) return 2;
    // else curOp must be 3
    if(prevOp == 3) return 0;//double inverse
    else if(prevOp == 1) return 2; // 1 change to 2
    else if(prevOp == 2) return 1; // 2 change to 1
    else return 3; // prevOp is 0
}

void updateLazy(int idx, int low, int high){
    // apply lazy to child if not leaf & has lazy
    if(lazy[idx] && low != high){
        int mid = (low+high)/2;
        lazy[idx*2+1] = combineOp(lazy[idx*2+1],lazy[idx]);
        lazy[idx*2+2] = combineOp(lazy[idx*2+2],lazy[idx]);
    }
    if(lazy[idx] == 1){
        // mod to 0
        segment[idx] = 0;
    } else if(lazy[idx] == 2){
        // mod to all 1
        segment[idx] = high-low+1;
    } else if(lazy[idx] == 3){
        // inverse
        segment[idx] = (high-low+1) - segment[idx];
    }
    lazy[idx] = 0;
}

int query(int idx, int low, int high, int qlow, int qhigh){
    updateLazy(idx,low,high);
    // no overlap
    if(qlow > high || qhigh < low) return 0;
    // full overlap
    else if(qlow <= low && high <= qhigh) return segment[idx];
    // partial overlap
    int mid = (low+high)/2;
    return query(idx*2+1,low,mid,qlow,qhigh) + query(idx*2+2,mid+1,high,qlow,qhigh);
}

void update(int idx, int low, int high, int ops, int qlow, int qhigh){
    updateLazy(idx,low,high);
    // no overlap
    if(qlow > high || qhigh < low) return;
    // full overlap
    else if(qlow <= low && high <= qhigh) {
        lazy[idx] = ops;
        updateLazy(idx,low,high);
    // partial overlap
    } else {
        int mid = (low+high)/2;
        update(idx*2+1, low , mid, ops, qlow, qhigh);
        update(idx*2+2, mid+1, high, ops, qlow, qhigh);
        segment[idx] = segment[idx*2+1] + segment[idx*2+2];
    }
}

int main() {
    int t,m,r,a,b;
    char c;
    char in[100];
    cin >> t;
    int cases = 1;
    while(t--){
        scanf("%d", &m);
        int n = 0;
        while(m--) {
            scanf("%d %s", &r, in);
            while(r--) {
                for(int i = 0; in[i]; i++, n++)
                    str[n] = in[i];
            }
        }
        n--;
        build(0,0,n);
        cin >> m;
        printf("Case %d:\n",cases++);
        int queryCnt = 1;
        for(int i=0;i<m;i++){
            cin >> c >> a >> b;
            if(c == 'F') {
                update(0,0,n,2,a,b);
            } else if(c == 'E'){
                update(0,0,n,1,a,b);
            } else if(c == 'I'){
                update(0,0,n,3,a,b);
            } else {
                cout << "Q" << queryCnt++ << ": " << query(0,0,n,a,b) << endl;
            }
        }
    }
}
