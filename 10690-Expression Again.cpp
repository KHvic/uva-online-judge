#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,v;
    while(scanf("%d %d",&n,&m) != EOF){
        vector<int> nums;
        if(m<n) swap(n,m);
        int sum = 0;
        for(int i=0;i<(n+m);i++){
            scanf("%d",&v);
            nums.push_back(v+50);
            sum += nums.back();
        }
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        dp[0][0] = true;

        // foreach num, foreach subset size, foreach sum
        for(int i=0;i<nums.size();i++) // num state first to avoid duplicate
            for(int j=n-1;j>=0;j--) // larger j first, because can only use this number once
                for(int k=nums[i];k<=sum;k++)
                    if(dp[j][k-nums[i]])
                        dp[j+1][k] = true;
        int maximum = INT_MIN, minimum = INT_MAX;
        for(int i=0;i<=sum;i++)
        if(dp[n][i]){
            int sum_n = i+(-50*n);
            int sum_m = sum-i+(-50*m);
            int prod = sum_n * sum_m;
            maximum = max(prod,maximum);
            minimum = min(prod,minimum);
        }
        printf("%d %d\n",maximum,minimum);
    }
}
