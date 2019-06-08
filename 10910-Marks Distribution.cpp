#include <bits/stdc++.h>
using namespace std;

int main()
{
    // dp to compute number ways to reach value j with i subjects
    long long dp[101][101] = {1};
    // for each subject i
    for (int i = 1; i <= 100; i++){
        dp[i][0] = 1;
        // for each total value j
        for (int j = 1; j <= 100; j++)
            // we could decide to add 1 to this subject to obtain j (dp[i][j-1])
            // or not add (dp[i-1][j])
            dp[i][j] = dp[i - 1][j] + dp[i][j-1];
    }
    int n, t, p, tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d %d",&n,&t,&p);
        t -= n * p; // start score from zero after subtracting minimum needed score
        printf("%lld\n", t >= 0 ? dp[n][t] : 0);
    }
    return 0;
}
