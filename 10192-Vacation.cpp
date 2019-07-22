#include <bits/stdc++.h>

using namespace std;
string a,b;

int main()
{
    int tc=1;
    while(getline(cin,a), a != "#"){
        getline(cin,b);
        vector<int> dp(b.length()+1);
        for(int i=0;i<a.length();i++){
            vector<int> nextDp(b.length()+1);
            for(int j=0;j<b.length();j++){
                if(a[i] == b[j])
                    nextDp[j+1] = dp[j] + 1;
                else
                    nextDp[j+1] = max(dp[j+1],nextDp[j]);
            }
            dp = nextDp;
        }
        printf("Case #%d: you can visit at most %d cities.\n",tc++,dp.back());
    }
}
