#include <bits/stdc++.h>
using namespace std;

/*
Knuth Speedup says that the optimal root for a problem i < m < t, where optimal(x,y) is the optimal root between x and y then
optimal(i, j) lies between optimal(i,m-1) to optimal(m+1,j) <- use an index table to store optimal root

Simplify: the optimal root of a problem lies between the optimal root of its sub-problem.
This only applies if the Quadrangle Inequality property is satisfied
*/

int dp[251][251]; // state: left, right
int optimal[251][251]; // optimal root index table for knuth optimization
int sum[251]; // for acquiring range sum between left, right
int n, v;


int main() {
    while(scanf("%d",&n) != EOF) {
        memset(sum, 0, sizeof sum);
        memset(optimal, 0, sizeof dp);
        for(int i=0;i<n;i++){
            scanf("%d", sum+i+1);
            sum[i+1] += sum[i];
            optimal[i][i] = i;
            dp[i][i] = 0;
        }

        for(int len=1;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j = i+len;
                // knuth optimization
                dp[i][j] = 1e7;
                for(int m=optimal[i][j-1]; m<=optimal[i+1][j];m++){
                    int left_cost = dp[i][m-1] + sum[m] - sum[i];
                    int right_cost = dp[m+1][j] + sum[j+1] - sum[m+1];
                    int total_cost = left_cost + right_cost;
                    if(total_cost < dp[i][j]) {
                        dp[i][j] = total_cost;
                        optimal[i][j] = m;
                    }
                }
            }
        }
        printf("%d\n", dp[0][n-1]);
    }
}
