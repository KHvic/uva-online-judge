#include <bits/stdc++.h>
using namespace std;

int tc,n,v;
vector<int> candies;
vector<int> cul_sum;
// can we reach this state?
bool dp[33][641][641]; // state: candyIdx, giveA, giveB: infer giveC with sum-giveA-giveB

int max_diff(int a, int b, int c){
    int highest = max(a, max(b, c));
    int lowest = min(a, min(b, c));
    return highest - lowest;
}

int main() {
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d",&n);
        memset(dp, 0, sizeof dp);
        candies.clear();
        cul_sum.assign(1, 0);
        for(int j=0;j<n;j++){
            scanf("%d",&v);
            candies.push_back(v);
            cul_sum.push_back(cul_sum.back() + v);
        }

        dp[0][0][0] = 1;
        for(int i=0;i<n;i++){
            int sum = cul_sum[i];
            for(int j=0;j<=sum;j++){
                for(int k=0;k<=sum;k++){
                    if(dp[i][j][k] == 0) continue;
                    int a = j, b = k;
                    int c = sum - a - b; // infer c from a & b
                    if(c < 0) continue;
                    int next_a = a + candies[i], next_b = b + candies[i], next_c = c + candies[i];
                    dp[i+1][next_a][b] = dp[i+1][a][next_b] = dp[i+1][a][b] = 1;
                }
            }
        }

        int res = 1e7;
        int sum = cul_sum.back();
        for(int j=0;j<=sum;j++)
            for(int k=0;k<=sum;k++)
                if(dp[n][j][k] != 0 && sum-j-k >= 0)
                    res = min(res, max_diff(j,k,sum-j-k));
        printf("Case %d: %d\n", t, res);
    }
}
