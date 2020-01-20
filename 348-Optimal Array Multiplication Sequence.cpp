#include <bits/stdc++.h>
using namespace std;
int tc=1,s,m,n;
int A[12];
int dp[12][12]; // state: low, high
int dp_path[12][12]; // store best mid among low to high
void print_path(int i,int j)
{
    if(i==j) {
        printf("A%d",i);
    } else {
        printf("(");
        print_path(i,dp_path[i][j]);
        printf(" x ");
        print_path(dp_path[i][j]+1,j);
        printf(")");
    }
}

int main()
{
    while(scanf("%d",&s), s)
    {
        int idx=0;
        for(int i=0;i<s;i++) {
            scanf("%d %d",&m,&n);
            if(i==0) {
                A[idx++]=m;
            }
            A[idx++]=n;
        }

        memset(dp, 0, sizeof dp);
        for(int l=2;l<=s;l++) { // length of matrix multiplication
            for(int i=1;i<=s+1-l;i++) { // start
                int j=i+l-1; // end
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++) { // try all midpoint between start and end
                    // dp[i][m] + dp[m+1][j] + A[i-1]*A[m]*A[j]
                    int cost=dp[i][k]+dp[k+1][j];
                    cost+=A[i-1]*A[k]*A[j];
                    if(cost<dp[i][j]) {
                        dp[i][j]=cost;
                        dp_path[i][j]=k;
                    }
                }
            }
        }
        printf("Case %d: ",tc++);
        print_path(1,s);
        printf("\n");
    }
}
