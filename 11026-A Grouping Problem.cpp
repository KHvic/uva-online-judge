#include <bits/stdc++.h>
using namespace std;
/*
If C[m][k] denotes the sum of products of elements of all subsets of size k chosen from first m elements,
then we have: C[m][k] = C[m-1][k] + C[m-1][k-1] * A[m], (where A[m] is m-th number in input.)
Example: consider a,b,c - pascal triangle (same as binomial coefficient)
// to compute for abc, we take sum to get to (ab) multiply by value of c + all sum of all length 3 subset
m=0       (1)
m=1    (1)(a)(0)
m=2  (1)(a)(ab)(0)
m=3(1)(a)(ab)(abc)(0)
*/
long long dp[1001][1001];
int main() {
    int n,m,v;
    while(scanf("%d %d",&n,&m),(n+m)) {
        vector<int> nums(1);
        for(int i=1;i<=n;i++){
            cin >> v;
            nums.push_back(v);
        }
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for(int j = 1; j <= i; j++) {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*nums[i]) % m;
            }
        }
        long long res = 0;
        for(int i = 1; i <= n; i++) res = max(dp[n][i], res);
        printf("%lld\n", res);
    }
}
