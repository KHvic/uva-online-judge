#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,m,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        vector<int> dp(m+1);
        for(int i=0;i<n;i++){
            vector<int> dpNext(m+1,INT_MIN);
            for(int j=1;j<=m;j++){
                scanf("%d",&v);
                for(int k=m;k>=j && v>=5;k--)
                    if(dp[k-j] != INT_MIN)
                        dpNext[k] = max(dp[k-j] + v, dpNext[k]);
            }
            dp = dpNext;
        }
        if(dp.back() == INT_MIN)
            printf("Peter, you shouldn't have played billiard that much.\n");
        else
            printf("Maximal possible average mark - %.2f.\n",(dp.back()+1e-9)/n);
    }
}
