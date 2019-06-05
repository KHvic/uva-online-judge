#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,p,n,b;
    cin >> t;
    while(t--){
        cin >> p;
        cin >> n;
        vector<int> bills;
        int sum = 0;
        for(int i=0;i<n;i++){
            cin >> b;
            bills.push_back(b);
            sum+=b;
        }
        vector<int> dp(sum+1,1e8);
        dp[0] = 0;
        for(auto& bill : bills)
            for(int i=sum;i>=bill;i--)
                if(dp[i-bill] != 1e8)
                    dp[i] = min(dp[i],dp[i-bill]+1);

        while(dp[p]==1e8)p++;
        printf("%d %d\n",p,dp[p]);
    }
}
