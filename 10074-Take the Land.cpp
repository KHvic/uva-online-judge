#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m),n||m){
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&dp[i][j]);
            dp[i][j] += (dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
        }
        int best = 0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        for(int k=i;k<=n;k++) for(int l=j;l<=m;l++){
            int cur = dp[k][l] - dp[i-1][l] - dp[k][j-1] + dp[i-1][j-1];
            if(cur == 0)
                best = max(best,(k-i+1)*(l-j+1));
            // we can do additional pruning if not 0
        }
        printf("%d\n",best);
    }
}
