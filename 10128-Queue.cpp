#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use 20 because test queries contains > 13
    long long dp[20][20][20];
    memset(dp,0,sizeof(dp));
    dp[1][1][1] = 1; // dp[N][P][R]
    // assume we are choosing the spot of the shortest person
    // he has to be in the next front, next back, or any middle spot
    for(int N=2;N<14;N++)
    for(int P=1;P<=N;P++)
    for(int R=1;R<=N;R++){
        // choose any spot not at either end, there are N-2 positions
        long long middle = dp[N-1][P][R]*(N-2);
        // either end
        long long front = dp[N-1][P-1][R];
        long long back = dp[N-1][P][R-1];
        dp[N][P][R] = middle+front+back;
    }
    int t,n,p,r;
    cin >> t;
    while(t--){
        cin >> n >> p >> r;
        printf("%lld\n", dp[n][p][r]);
    }
}
