#include <bits/stdc++.h>
using namespace std;

// idea: twice the initial length of matrix to handle wrap-around

int main()
{
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> dp(n*2+1,vector<int>(n*2+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&dp[i][j]);
                dp[i][j+n] = dp[i+n][j] = dp[i+n][j+n] = dp[i][j];
            }
        }
        // running sum
        for(int i=1;i<=2*n;i++)
        for(int j=1;j<=2*n;j++){
            dp[i][j] += (dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]);
        }
        // dp
        int res = INT_MIN;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        for(int k=i;k<i+n;k++) for(int l=j;l<j+n;l++){
            int cur = dp[k][l] - dp[i-1][l] - dp[k][j-1] + dp[i-1][j-1];
            res = max(cur,res);
        }
        printf("%d\n",res);
    }
}
