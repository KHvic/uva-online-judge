#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int sum = 0;
        vector<int> coins;
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            coins.push_back(v);
            sum += v;
        }
        vector<bool> dp(sum/2+1);
        dp[0] = true;
        int highest = 0;
        for(auto& coin : coins){
            for(int i=sum/2;i>=coin;i--){
                dp[i] = dp[i-coin] ? true : dp[i];
                if(dp[i]) highest = max(i,highest);
            }
        }
        int res = sum-highest*2;
        printf("%d\n",res);
    }
}
