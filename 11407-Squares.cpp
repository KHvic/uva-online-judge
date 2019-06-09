#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> dp(10001,1e7);
    dp[0] = 0;
    for(int i=1;i*i<=10000;i++){
        int num = i*i;
        for(int j=num;j<=10000;j++)
            dp[j] = min(dp[j],dp[j-num]+1);
    }
    int t,v;
    cin >> t;
    while(t--){
        scanf("%d",&v);
        printf("%d\n",dp[v]);
    }
}
