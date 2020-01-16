#include <bits/stdc++.h>
using namespace std;

int tc,n,m;
int dp[102][1<<10][10]; // state: number digits, used digit mask, last digit
int mod = 1000000007;

int main() {
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&n,&m);
        memset(dp, 0, sizeof dp);
        int sum = 0;
        // init m = 0
        for(int i=1;i<n;i++) dp[0][1<<i][i] = 1;
        for(int i=0;i<m;i++){ // each digit
            for(int j=0;j<(1<<n);j++){ // used digits bitmask
                for(int k=0;k<n;k++){ // last digit
                    // k -1
                    if(k>0) {
                        dp[i+1][j|(1<<(k-1))][k-1] = (dp[i+1][j|(1<<(k-1))][k-1] + dp[i][j][k])%mod;
                    }
                    if(k<n-1) {
                        dp[i+1][j|(1<<(k+1))][k+1] = (dp[i+1][j|(1<<(k+1))][k+1] + dp[i][j][k])%mod;
                    }

                    if(j==((1<<n)-1)) sum = (sum+dp[i][j][k])%mod;
                }
            }
        }

        printf("%d\n",sum);
    }
}
