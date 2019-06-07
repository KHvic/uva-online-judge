#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k,v;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<bool> dp(k,false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            cin >> v;
            vector<bool> dpNext(k,false);
            // can try using an unordered_set on j for better performance
            for(int j=0;j<k;j++)
            if(dp[j]){
                for(int mult : {-1,1}){
                    int idx = (((j+mult*v)%k)+k)%k;
                    dpNext[idx] = true;
                }
            }
            dp = dpNext;
        }
        if(dp[0]) printf("Divisible\n");
        else printf("Not divisible\n");
    }
}
