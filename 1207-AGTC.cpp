#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1,n2;
    string a,b;
    while(cin >> n1){
        cin >> a >> n2 >> b;
        vector<int> dp(b.length()+1);
        for(int i=0;i<=b.length();i++)
            dp[i] = i;
        for(int i=0;i<a.length();i++){
            vector<int> dpNext(b.length()+1);
            dpNext[0] = i+1;
            for(int j=0;j<b.length();j++){
                if(a[i]==b[j])
                    dpNext[j+1] = dp[j];
                else
                    dpNext[j+1] = min(dpNext[j],min(dp[j],dp[j+1]))+1;
            }
            dp = dpNext;
        }
        printf("%d\n",dp.back());
    }
}
