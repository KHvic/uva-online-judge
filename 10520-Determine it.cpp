#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,v;
    while(scanf("%d %d",&n,&v) != EOF){
        long long a[50][50] = {};
        a[n][1] = v;
        for(int i=n; i>= 1; i--){
            for(int j=1; j<=n; j++){
                if(j==1 && i==n)
                    continue;
                if(i>=j){
                    long long left = 0, right = 0;
                    for(int k=i+1;k<=n;k++)
                        left = max(a[k][1]+a[k][j], left);
                    for(int k=1;k<j;k++)
                        right = max(a[i][k]+a[n][k],right);
                    a[i][j] = left+right;
                } else {
                    for(int k=i;k<j;k++)
                        a[i][j] = max(a[i][k]+a[k+1][j],a[i][j]);
                }
            }
        }
        printf("%lld\n",a[1][n]);
    }
}
