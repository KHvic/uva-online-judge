#include <bits/stdc++.h>
using namespace std;

int main() {
    // dp[i][j][k]
    // state: num people, person first, k: 0 - shorter person now, 1 - taller person now
    long long dp[30][30][2];
    memset(dp, 0, sizeof dp);
    dp[1][1][0] = dp[1][1][1] = 1;
    for(int i=2; i<30; i++) { // i people
        for(int j=1; j<=i; j++) { // midpoint j selected to be the first person
            // 1 to j-1, people shorter than j
            for(int k=1; k<j; k++)
                dp[i][j][1] += dp[i-1][k][0]; // += seq of i-1 people with next shorter person being k
            // j to i, people taller than j
            for(int k=j; k<=i; k++)
                dp[i][j][0] += dp[i-1][k][1]; // += seq of i-1 people with next taller person being k
        }
    }
    int n, m;
    while(scanf("%d %d", &n, &m) == 2) {
        long long res = 0;
        // team captain m has to be the first, and player next to him should be shorter if possible
        if(m > 1) {
            // not shortest first
            res = dp[n][m][1];
        } else {
            // shortest first special case
            if(n <= 2)
                res = 1;
            else
                // only 2 can be beside captain when m = 1
                res = dp[n-1][2][1];// (1,2,...)
        }
        printf("%lld\n", res);
    }
    return 0;
}
