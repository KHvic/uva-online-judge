#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    while(getline(cin,a)){
        getline(cin,b);
        vector<int> dp(b.length()+1);
        for(int i=0;i<a.length();i++){
            int prev = 0;
            for(int j=0;j<b.length();j++){
                int tmp = dp[j+1];
                if(a[i] == b[j]) dp[j+1] = prev+1;
                else dp[j+1] = max(dp[j],dp[j+1]);
                prev = tmp;
            }
        }
        printf("%d\n",dp.back());
    }
}
