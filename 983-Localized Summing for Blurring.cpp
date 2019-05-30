#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    bool first = true;
    while(scanf("%d %d",&n,&m) != EOF){
        if(!first) printf("\n");
        first = false;
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        {
            scanf("%d",&dp[i+1][j+1]);
            dp[i+1][j+1] += (dp[i][j+1]+dp[i+1][j]-dp[i][j]);
        }
        int total = 0;
        for(int i=m;i<=n;i++)
        for(int j=m;j<=n;j++){
            int cur = dp[i][j];
            cur += (dp[i-m][j-m]-dp[i-m][j]-dp[i][j-m]);
            printf("%d\n",cur);
            total += cur;
        }
        printf("%d\n",total);
    }
}
