#include <bits/stdc++.h>
using namespace std;

#define N 11
#define M 101

// state, n mailboxes, low, high
int dp[N][M][M];
int main(){
    for (int i=0;i<M;i++) for(int j=i;j<M;j++)
        if(i==j) dp[0][i][j] = 0;
        else dp[0][i][j] = dp[0][j][i] = 1e7;

    for(int i=1;i<N;i++){//mailboxes
        for(int j=1;j<M;j++){//range, smaller range need to be solved first
            for(int k=0;k+j<M;k++){//start
                int best = 1e7;
                for(int m=k+1;m<=k+j;m++){//midpoint
                    int explode = dp[i-1][k][m-1];
                    int not_explode = dp[i][m][k+j];
                    best = min(best, max(explode, not_explode) + m);
                }
                dp[i][k][k+j] = best;
            }
        }
    }
    int k, m, t;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d",&k,&m);
        printf("%d\n",dp[k][0][m]);
    }
}
