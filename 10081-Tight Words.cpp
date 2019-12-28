#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;

    while(scanf("%d %d",&k,&n) == 2){
        vector<vector<double>> dp(n+2, vector<double>(k+2));
        // dp state: count_alpha, last alphabet k  (xxxxxk)
        for(int i=0;i<=k;i++) dp[1][i] = 1;
        for(int i=2;i<=n;i++){
            dp[i][0] = dp[i][k] = dp[i-1][0] + dp[i-1][1]; // first and last digit only have one neighbor (symmetry)
            for(int j=1;j<k;j++)
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
        }
        // probability = sum(dp[n])/ total_permutation
        double total_count = 0;
        for(int i=0;i<=k;i++) total_count += dp[n][i];
        double res = 100.0*total_count/pow((double)k+1,n);
        printf("%.5f\n",res);
    }
}
