#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string in;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,in);
        vector<vector<long long>> dp(in.length(),vector<long long>(in.length()));
        for(int i=0;i<in.length();i++) dp[i][i] = 1;
        for(int start=in.length()-1;start>=0;start--){
            for(int end=start+1;end<in.length();end++){
                if(in[start]==in[end]) // include this as palindrome, already double counted
                    dp[start][end] = dp[start][end-1] + dp[start+1][end] + 1;
                else // double counted [start+1][end-1], need to remove overlap
                    dp[start][end] = dp[start][end-1] + dp[start+1][end] - dp[start+1][end-1];
            }
        }
        printf("%lld\n",dp[0].back());
    }
}
