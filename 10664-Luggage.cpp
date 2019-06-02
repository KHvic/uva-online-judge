#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,v;
    string in;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,in);
        istringstream iss(in);
        vector<int> nums;
        int sum = 0;
        while(iss >> v){
            sum += v;
            nums.push_back(v);
        }
        if(sum%2) printf("NO\n");
        else {
            sum/=2;
            vector<bool> dp(sum+1);
            dp[0] = true;
            for(auto& num : nums){
                for(int i=sum;i>=num;i--)
                    dp[i] = dp[i-num] ? true : dp[i];
            }
            if(dp[sum]) printf("YES\n");
            else printf("NO\n");
        }
    }
}
