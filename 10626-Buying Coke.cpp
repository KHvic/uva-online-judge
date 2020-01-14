#include <bits/stdc++.h>
using namespace std;

int tc, n, a, b, c, sum;
int dp[152][155][52]; // state: cokeIdx, num 5, num 10

int main() {
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d %d %d",&n,&a,&b,&c);
        memset(dp, -1, sizeof dp);
        dp[0][b][c] = 0;
        sum = c*10+b*5+a;
        for(int i=0;i<n;i++){
            int money_left = sum - i*8;
            for(int j=0;j<=c+b;j++){
                for(int k=0;k<=c;k++){
                    if(dp[i][j][k] == -1) continue;
                    int remain1 = money_left - j*5 - k*10;
                    // use 10
                    if(k>=1){
                        if(dp[i+1][j][k-1] == -1) dp[i+1][j][k-1] = 1e7;
                        dp[i+1][j][k-1] = min(dp[i+1][j][k-1], 1+dp[i][j][k]);
                    }
                    // use 10 and three 1
                    if(k>=1 && remain1>=3){
                        if(dp[i+1][j+1][k-1] == -1) dp[i+1][j+1][k-1] = 1e7;
                        dp[i+1][j+1][k-1] = min(dp[i+1][j+1][k-1], 4+dp[i][j][k]);
                    }

                    // use double 5
                    if(j>=2) {
                        if(dp[i+1][j-2][k] == -1) dp[i+1][j-2][k] = 1e7;
                        dp[i+1][j-2][k] = min(dp[i+1][j-2][k], 2+dp[i][j][k]);
                    }
                    // use one 5, three 1
                    if(remain1>=3 && j>=1){
                        if(dp[i+1][j-1][k] == -1) dp[i+1][j-1][k] = 1e7;
                        dp[i+1][j-1][k] = min(dp[i+1][j-1][k], 4+dp[i][j][k]);
                    }
                    // use eight 1
                    if(remain1>=8){
                        if(dp[i+1][j][k] == -1) dp[i+1][j][k] = 1e7;
                        dp[i+1][j][k] = min(dp[i+1][j][k], 8+dp[i][j][k]);
                    }
                }
            }
        }
        int best = 1e7;
        for(int j=0;j<=c+b;j++)
            for(int k=0;k<=c;k++)
                if(dp[n][j][k] != -1) best = min(best, dp[n][j][k]);
        printf("%d\n", best);
    }
}
