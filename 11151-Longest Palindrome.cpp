#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string in;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,in);
        vector<vector<int>> dp(in.length(),vector<int>(in.length(),0));
        
        for(int j=in.length()-1;j>=0;j--){
            dp[j][j] = 1;
            for(int i=j+1;i<in.length();i++){
                if(in[i] == in[j]){
                    dp[j][i] = dp[j+1][i-1] + 2;
                } else {
                    dp[j][i] = max(dp[j][i-1],dp[j+1][i]);
                }
            }
        }
        if(in.empty()) printf("0\n");
        else
            printf("%d\n",dp[0][in.length()-1]);
    }
}
