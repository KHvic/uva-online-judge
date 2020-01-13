#include <bits/stdc++.h>
using namespace std;

int tc,n,v;
vector<int> candies;
vector<int> cul_sum;
int dp[33][641][641];

int max_diff(int a, int b, int c){
    int highest = max(a, max(b, c));
    int lowest = min(a, min(b, c));
    return highest - lowest;
}

int main() {
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d",&n);
        memset(dp, -1, sizeof dp);
        candies.clear();
        cul_sum.assign(1, 0);
        for(int j=0;j<n;j++){
            scanf("%d",&v);
            candies.push_back(v);
            cul_sum.push_back(cul_sum.back() + v);
        }

        dp[0][0][0] = 0;
        for(int i=0;i<n;i++){
            int sum = cul_sum[i];
            for(int j=0;j<=sum;j++){
                for(int k=0;k<=sum;k++){
                    if(dp[i][j][k] == -1) continue;
                    int a = j, b = k;
                    int c = sum - a - b; // infer c from a & b
                    if(c < 0) continue;
                    int next_a = a + candies[i], next_b = b + candies[i], next_c = c + candies[i];
                    if(dp[i+1][next_a][b] == -1) dp[i+1][next_a][b] = 1e7;
                    if(dp[i+1][a][next_b] == -1) dp[i+1][a][next_b] = 1e7;
                    if(dp[i+1][a][b] == -1) dp[i+1][a][b] = 1e7;
                    dp[i+1][next_a][b] = min(dp[i+1][next_a][b], max_diff(next_a ,b ,c));
                    dp[i+1][a][next_b] = min(dp[i+1][a][next_b], max_diff(a, next_b, c));
                    dp[i+1][a][b] = min(dp[i+1][a][b], max_diff(a, b, next_c));
                }
            }
        }

        int res = 1e7;
        for(int j=0;j<=cul_sum.back();j++)
            for(int k=0;k<=cul_sum.back();k++)
                if(dp[n][j][k] != -1)
                    res = min(res, dp[n][j][k]);
        printf("Case %d: %d\n", t, res);
    }
}
