#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,l,m;
    while(scanf("%d",&n),n){
        vector<vector<int>> blockCount(101,vector<int>(101));
        vector<vector<int>> dp(101,vector<int>(101));
        for(int i=0;i<n;i++){
            scanf("%d %d",&l,&m);
            blockCount[l][m]++;
        }
        for(int i=1;i<101;i++)
        for(int j=1;j<101;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + blockCount[i][j];
        }
        printf("%d\n",dp[100][100]);
    }
    printf("*\n");
}
