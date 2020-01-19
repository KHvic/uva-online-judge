#include <bits/stdc++.h>
using namespace std;
#define ll long long

int d,g,tc=1;
// state: first project left, second project left, cur project
ll memo[34][34][2];

ll solve(int p1, int p2, int cur) {
    if(p1 == 0) {
        return cur == 1;
    } else if(p2 == 0) return 0; // p1 have to finish first
    ll &res = memo[p1][p2][cur];
    if(res != -1) return res;
    res = 0;
    for(int i=1;i<=g && i<=(cur?p2:p1);i++) {
        if(cur == 0)
            res += solve(p1 - i, p2, cur^1);
        else
            res += solve(p1, p2 - i, cur^1);
    }
    return res;
}

int main() {
    while(scanf("%d %d",&d,&g), (d+g) != -2){
        memset(memo, -1, sizeof memo);
        ll res = (g==0 || d==0) ? 0 : solve(d,d,0)*2; // multiply 2, for each starting project (symmetry)
        printf("Case %d: %lld\n", tc++, res);
    }
}
