#include <bits/stdc++.h>

using namespace std;

// idea: edit distance to reverted string divide by 2 (because of double counting)
int main()
{
    string a,b;
    int tc=1,t;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,a);
        b = a;
        reverse(b.begin(),b.end());

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
        printf("Case %d: %d\n",tc++,dp.back()/2);
    }
}

// alternative dp:
// let i=low, j=high
// if(str[i]==str[j]) return dp[i+1][j-1]
// else: 1 + min(dp[i+1][j-1] - edit
//               dp[i+1][j], dp[i][j-1]) - insert or remove
