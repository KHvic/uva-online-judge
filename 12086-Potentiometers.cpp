#include <bits/stdc++.h>
using namespace std;

int n;
int fenwick[200002];

void add(int i, int val){
    while(i<=n){
        fenwick[i] += val;
        i += (i&-i);
    }
}

int sum(int n){
    int res = 0;
    while(n>0) {
        res += fenwick[n];
        n -= (n&-n);
    }
    return res;
}

int query(int l, int r){
    return sum(r) - sum(l-1);
}

int main() {
    int v;
    int l,r;
    string c;
    int cases = 1;
    while(scanf("%d",&n),n){
        vector<int> vals;
        memset(fenwick,0,sizeof(fenwick));
        for(int i=0;i<n;i++) {
            cin >> v;
            add(i+1,v);
            vals.push_back(v);
        }
        if(cases > 1) cout << endl;
        printf("Case %d:\n",cases++);
        while(cin >> c, c != "END"){
            cin  >> l >> r;
            if(c == "S") {
                int diff = r - vals[l-1];
                add(l, diff);
                vals[l-1] = r;
            } else {
                cout << query(l,r) << endl;
            }
        }
    }
}
