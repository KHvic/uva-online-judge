#include <bits/stdc++.h>
using namespace std;

// alternate method to solve it more efficiently is to use stack
// compute 'largest zero histogram' for each row O(N^2)

int main()
{
    int t,n,b,r1,c1,r2,c2;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&b);
        vector<vector<int>> commands(n+2,vector<int>(n+2));
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        while(b--){
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            // transform into representation that can be derived
            commands[r1][c1] += 1;
            commands[r2+1][c1] -= 1;
            commands[r1][c2+1] -= 1;
            commands[r2+1][c2+1] += 1;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            // derive original array and perform dp
            commands[i][j] += (commands[i-1][j]+commands[i][j-1]-commands[i-1][j-1]);
            dp[i][j] = commands[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
        int res = 0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        for(int k=i;k<=n;k++) for(int l=j;l<=n;l++){
            int cur = dp[k][l]-dp[k][j-1]-dp[i-1][l]+dp[i-1][j-1];
            if(cur == 0)
                res = max(res,(k-i+1)*(l-j+1));
        }
        printf("%d\n",res);
    }
}
