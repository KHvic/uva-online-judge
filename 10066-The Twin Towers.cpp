#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,v,tc=1;
    while(scanf("%d %d",&a,&b),(a+b)!=0){
        vector<int> dp(a+1);
        vector<int> towerA;
        for(int i=0;i<a;i++){
            scanf("%d",&v);
            towerA.push_back(v);
        }
        for(int i=0;i<b;i++){
            scanf("%d",&v);
            vector<int> dpNext(a+1);
            for(int j=0;j<a;j++){
                if(v == towerA[j])
                    dpNext[j+1] = dp[j]+1;
                else
                    dpNext[j+1] = max(dp[j+1],dpNext[j]);
            }
            dp = dpNext;
        }
        printf("Twin Towers #%d\n",tc++);
        printf("Number of Tiles : %d\n\n",dp.back());
    }
}
