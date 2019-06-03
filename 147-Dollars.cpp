#include <bits/stdc++.h>
using namespace std;

int main()
{
    int coins[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
    long long dp[30001] = {};
    dp[0] = 1;
    for(auto& coin : coins)
        for(int i=coin;i<30001;i++)
            dp[i] += dp[i-coin];
    double in;
    while(scanf("%lf",&in),in)
        printf("%6.2f%17lld\n",in,dp[(int)round(in*100)]);
}
