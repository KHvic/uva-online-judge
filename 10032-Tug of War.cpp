#include <bits/stdc++.h>
using namespace std;

// knapsack/subset sum trick when n<=64, we can use bitmask
int main()
{
    int tc,n,v;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        int sum=0;
        vector<int> weights;
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            weights.push_back(v);
            sum+=v;
        }
        int half_sum = sum/2;
        int half_ppl = n/2;
        // dp bitmask, each bit i representing whether i people can form it
        vector<long long> dp(half_sum+1);
        dp[0]=1;
        for(int i=0;i<n;i++)
            for(int j=half_sum;j>=weights[i];j--)
                dp[j] |= (dp[j-weights[i]] << 1LL); // shift one as dp[n][j] |= dp[n-1][j-weights[i]]
        int best=-1;
        for(int i=half_sum;i>=0&&best==-1;i--){
            if(dp[i] & (1LL<<half_ppl)) best=i;
            else if(n%2 && dp[i] & (1LL<<(half_ppl+1))) best=i;
        }
        printf("%d %d\n",best,sum-best);
        if(tc) printf("\n");
    }
}
