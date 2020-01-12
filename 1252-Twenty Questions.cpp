#include <bits/stdc++.h>
using namespace std;

int m,n,f;
int dp[1<<11][1<<11];
vector<int> objects;

// dp state: questions asked, description of features
int solve(int ask, int describe){
    if(dp[ask][describe] != -1) return dp[ask][describe];

    int matching = 0;
    for(int object : objects)
        if((object & ask) == describe)
            matching++;
    // only one matches, must be this object
    if(matching <= 1) return dp[ask][describe] = 0;

    int best = m+1;
    for(int i=0;i<m;i++)
    if((ask & (1<<i))==0){
        int next_ask = ask | (1<<i);
        // could be either true or false, take the maximum required
        int res = max(solve(next_ask, describe), solve(next_ask, describe | (1<<i)));
        best = min(best, res + 1);
    }
    return dp[ask][describe] = best;
}

int main() {
    while(scanf("%d %d",&m,&n),m+n){
        memset(dp, -1, sizeof dp);
        objects.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&f);
            int bitmask = 0;
            for(int j=0;j<m;j++){
                if(f%2) bitmask |= 1<<j;
                f/=10;
            }
            objects.push_back(bitmask);
        }
        printf("%d\n", solve(0,0));
    }
}
