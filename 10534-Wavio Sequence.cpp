#include <bits/stdc++.h>
using namespace std;

void lis(vector<int>& nums,vector<int>& dp){
    vector<int> LIS;
    for(int i=0;i<nums.size();i++){
        int pos = lower_bound(LIS.begin(),LIS.end(),nums[i]) - LIS.begin();
        if(pos == LIS.size()) LIS.push_back(nums[i]);
        else LIS[pos] = nums[i];
        dp.push_back(pos+1);
    }
}

int main()
{
    int n,v;
    while(scanf("%d",&n) != EOF){
        vector<int> dp,dp_reverse;
        vector<int> nums;
        while(n--){
            scanf("%d",&v);
            nums.push_back(v);
        }

        lis(nums,dp);
        reverse(nums.begin(),nums.end());
        lis(nums,dp_reverse);

        int res = 1;
        for(int i=0;i<nums.size();i++){
            res = max(res,
                      2*min(dp[i],dp_reverse[nums.size()-1-i])-1);
        }
        printf("%d\n",res);
    }
}
