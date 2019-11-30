#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double p;
    while(scanf("%d %lf",&n,&p), n) {
        // dp[i][j] is the probability of winning streak j or less with i games
        vector<vector<double>> dp(n+1, vector<double>(n+1, 1));

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                // only way is to win all, 1-p^i to get excluded, subtract it
                if(i-1==j)
                    dp[i][j] = 1 - pow(p,i);
                else{
                    // scenario: ppppppLWWWWW
                    // p is previous (i-j-2) unknown, L is loss, WWWW is the j+1 winning streak
                    double previous = dp[i-j-2][j];
                    // probability of j+1 winning streak
                    double winningStreak = pow(p, j+1);

                    // subtract that possible scenario probability
                    dp[i][j] = dp[i-1][j] - previous*(1-p)*winningStreak;
                }
            }
        }
        double res = 0;
        for(int i=1;i<=n;i++)
            // dp[n][i] - dp[n][j-1] is the prob of i longest winning streak after n games
            res += (dp[n][i]-dp[n][i-1])*i;
        printf("%f\n",res);
    }
}
