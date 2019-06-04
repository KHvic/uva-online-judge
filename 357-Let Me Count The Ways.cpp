#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1,5,10,25,50};
vector<long long> dp(30001,0);

int main()
{
    dp[0] = 1;
    for(auto& coin : coins)
        for(int i=coin;i<30001;i++)
            dp[i] += dp[i-coin];
    int n;
    while(scanf("%d",&n) != EOF){
        if(dp[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",dp[n],n);
    }
}
