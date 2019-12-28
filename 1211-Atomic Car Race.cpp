#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,c;
    double b,r,v,e,f;
    while(scanf("%d",&n), n) {
        vector<int> checkpoints(1,0);
        for(int i=0;i<n;i++){
            scanf("%d",&c);
            checkpoints.push_back(c);
        }
        scanf("%lf %lf %lf %lf %lf",&b,&r,&v,&e,&f);

        // precompute cost of travelling x distance
        vector<double> cost(1,0);
        for(int x=1;x<=checkpoints[n];x++){
            double time;
            if(x-1 < r)
                time = cost[x-1]+1.0/(v-f*(r-x+1));
            else
                time = cost[x-1]+1.0/(v-e*(x-1-r));
            cost.push_back(time);
        }
        // dp
        vector<double> dp(n+1,1e20);
        dp[0] = 0;
        for(int i=0;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            // change tire at i and travel to j
            int dist = checkpoints[j]-checkpoints[i];
            double time_taken = dp[i]+cost[dist];
            if(i!=0) time_taken += b;
            dp[j] = min(dp[j], time_taken);
        }
        printf("%.4f\n", dp[n]);
    }
}
