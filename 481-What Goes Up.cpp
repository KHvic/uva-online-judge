#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,i=0;
    vector<int> nums;
    vector<int> lis;
    vector<int> idx; // store index of current lis in nums
    vector<int> prevIdx; // previous number index for the i number
    int last = 0; // last item idx
    while(scanf("%d",&v) != EOF)
    {
        nums.push_back(v);
        // patience sort, find position in LIS
        int pos = lower_bound(lis.begin(), lis.end(), v) - lis.begin();
        if(pos == lis.size()){
            lis.push_back(v);
            idx.push_back(nums.size()-1);
        } else {
            lis[pos] = v;
            idx[pos] = nums.size()-1;
        }
        // set previous item in LIS as parent
        prevIdx.push_back(pos ? idx[pos - 1] : -1);
        if(pos+1 >= lis.size()) last = idx.back();
    }
    printf("%d\n-\n",lis.size());
    stack<int> res;
    while(last != -1){
        res.push(nums[last]);
        last = prevIdx[last];
    }
    while(!res.empty())
        printf("%d\n",res.top()),res.pop();
}
