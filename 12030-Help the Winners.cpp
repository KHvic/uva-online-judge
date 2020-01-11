#include <bits/stdc++.h>
using namespace std;

int tc,n,v;
vector<vector<int>> match;
// state:(idx, bitmask, all1, has2)
long long dp[16][1<<16][2][2];

long long solve(int idx, int bitmask, bool all1, bool has2){
    if(idx == n){
        return all1 || has2;
    }
    if(dp[idx][bitmask][all1][has2] != -1) return dp[idx][bitmask][all1][has2];

    long long sum = 0;
    for(int i=0;i<n;i++)
        if((bitmask & (1<<i)) == 0)
            sum += solve(idx+1, bitmask | (1<<i), all1 && (match[idx][i] > 0), has2 || (match[idx][i] == 2));
    return dp[idx][bitmask][all1][has2] = sum;
}

int main() {
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d",&n);
        match.clear();
        memset(dp, -1, sizeof dp);
        for(int i=0;i<n;i++){
            vector<int> row;
            for(int j=0;j<n;j++){
                scanf("%d",&v);
                row.push_back(v);
            }
            match.push_back(row);
        }

        printf("Case %d: %lld\n",t,solve(0,0,true,false));
    }
}
