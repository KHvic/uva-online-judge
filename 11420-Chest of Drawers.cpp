#include <bits/stdc++.h>
using namespace std;

int main()
{
    // store [num drawers][num secured][bottom drawer locked?]
    long long dp[66][66][2] = {};
    dp[1][1][1] = 1, dp[1][0][0] = 1;
    for(int i=2;i<=65;i++){
        for(int s=0;s<=i;s++){
            dp[i][s][0] = dp[i-1][s][0] + dp[i-1][s][1];
            dp[i][s][1] = dp[i-1][s][0] + (s>0 ? dp[i-1][s-1][1] : 0);
        }
    }
    int n,s;
    while(scanf("%d %d",&n,&s), n>=0){
        printf("%lld\n",dp[n][s][0] + dp[n][s][1]);
    }
}
