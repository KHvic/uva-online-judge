#include <bits/stdc++.h>
using namespace std;
/*
If C[m][k] denotes the sum of products of elements of all subsets of size k chosen from first m elements,
then we have: C[m][k] = C[m-1][k] + C[m-1][k-1] * A[m], (where A[m] is m-th number in input.)
Example: consider a,b,c - pascal triangle (same as binomial coefficient)
// sX = sum of group size X
// each depth, consider a new character, to get to abc = sum(ab)*c + sum(length 3 groups) 
m=        (1)
m=a    (1)(s1)(0)
m=b  (1)(s1)(s2)(0)
m=c(1)(s1)(s2)(s3)(0)
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
