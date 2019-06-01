#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,v;
    scanf("%d",&t);
    while(t--){
        vector<int> nums;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            nums.push_back(v);
        }
        vector<int> LIS;
        deque<int> LDS;
        int res = 0;
        // from backwards, since we want to compute
        // and store the dp length at i
        for(int i=n-1;i>=0;i--){
            int lower = lower_bound(LIS.begin(),LIS.end(),nums[i]) - LIS.begin();
            int upper = upper_bound(LDS.begin(),LDS.end(),nums[i]) - LDS.begin();
            int dpInc, dpDec;
            if(lower == LIS.size()){
                LIS.push_back(nums[i]);
                dpInc = LIS.size();
            } else {
                LIS[lower] = nums[i];
                dpInc = lower+1;
            }
            if(upper == 0){
                LDS.push_front(nums[i]);
                dpDec = LDS.size();
            } else {
                LDS[upper-1] = nums[i];
                dpDec = LDS.size()-(upper-1);
            }
            res = max(res, dpInc+dpDec-1);
        }
        printf("%d\n",res);
    }
}
