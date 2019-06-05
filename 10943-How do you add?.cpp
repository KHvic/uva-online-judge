#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dp[101][101] = {};
    dp[0][0] = 1;
    // dp[n][k] = sum of dp[i][k-1] for i=0 to n
    // for each k
    for(int i=1;i<101;i++){
        // for each number n
        int sum = 0;
        for(int j=0;j<101;j++){
            sum = (sum+dp[j][i-1])%1000000;
            dp[j][i] = sum;
        }
    }
    int n,k;
    while(scanf("%d %d",&n,&k),(n+k) != 0){
        printf("%d\n",dp[n][k]);
    }
}
