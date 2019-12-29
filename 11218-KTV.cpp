#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b,c,s,tc=1;
    while(scanf("%d",&n),n){
        vector<pair<int,int>> scores;
        vector<int> dp(1<<9,-1);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            scanf("%d %d %d %d",&a,&b,&c,&s);
            a--, b--, c--;
            int bitmask = (1<<a)|(1<<b)|(1<<c);
            scores.push_back({bitmask,s});
        }
        for(auto& score : scores){
            int bitmask, val;
            tie(bitmask, val) = score;
            for(int i=0;i<(1<<9);i++){
                if((bitmask&i) == 0 && dp[i] != -1)
                    dp[i|bitmask] = max(dp[i|bitmask],dp[i]+val);
            }
        }
        printf("Case %d: %d\n", tc++, dp[(1<<9)-1]);
    }
}
