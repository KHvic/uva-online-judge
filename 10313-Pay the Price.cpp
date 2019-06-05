#include <bits/stdc++.h>
using namespace std;
int main()
{
    // dp[v][n] = num ways to form v using n coins
    vector<vector<long long>> dp(301,vector<long long>(301,0));
    dp[0][0] = 1;
    // for each coin value (smallest coin first)
    for(int i=1;i<=300;i++)
        // for each usage of the coin
        for(int j=1;j<=300;j++)
            // for each possible value
            for(int k=300;k>=i;k--)
                dp[k][j] += dp[k-i][j-1];

    string in;
    int v,left,right;
    while(getline(cin,in)){
        istringstream iss(in);
        vector<int> input;
        while(iss >> v) input.push_back(v);
        if(input.size() == 1){
            left = 0, right = 300;
        }else if(input.size() == 2){
            left = 0, right = input[1];
        } else {
            left = input[1], right = input[2];
        }
        long long sum =0;
        right = min(300,right);
        for(int i=left;i<=right;i++) sum += dp[input[0]][i];
        printf("%lld\n",sum);
    }
}
