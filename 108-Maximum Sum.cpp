#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        scanf("%d",&dp[i][j]);
        if(i) dp[i][j] += dp[i-1][j];
        if(j) dp[i][j] += dp[i][j-1];
        if(i && j) dp[i][j] -= dp[i-1][j-1];
    }
    int res = INT_MIN;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) // start coord
        for(int k=i;k<n;k++) for(int l=j;l<n;l++) // end coord
    {
        int rectSum = dp[k][l];
        if(i) rectSum -= dp[i-1][l];
        if(j) rectSum -= dp[k][j-1];
        if(i && j) rectSum += dp[i-1][j-1];
        res = max(res, rectSum);
    }
    printf("%d\n",res);
}
