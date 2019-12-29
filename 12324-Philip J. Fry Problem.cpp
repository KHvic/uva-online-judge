#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t,b;
    while(scanf("%d",&n),n){
        vector<pair<int,int>> trips;
        for(int i=0;i<n;i++){
            scanf("%d %d",&t,&b);
            trips.push_back({t,b});
        }
        vector<int> dp(n+1,1e7);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            tie(t,b) = trips[i];
            vector<int> next_dp(n+1,1e7);
            for(int j=0;j<=n;j++){
                int sphere_left = min(j+b,n);
                int no_use = dp[j] + t;
                next_dp[sphere_left] = min(next_dp[sphere_left], no_use);
                if(j>0){
                    int use = dp[j] + t/2;
                    sphere_left = min(j+b-1,n);
                    next_dp[sphere_left] = min(next_dp[sphere_left], use);
                }
            }
            dp = next_dp;
        }
        printf("%d\n",*min_element(dp.begin(), dp.end()));
    }
}
