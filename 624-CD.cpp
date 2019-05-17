#include <bits/stdc++.h>

using namespace std;
int res,best;
void dfs(int i, vector<int>& nums, int sum, int cur, int limit){
    if(sum > limit) return;
    else if(sum > best){
        best = sum;
        res = cur;
    }
    if(i >= nums.size()) return;
    dfs(i+1,nums,sum+nums[i],cur|(1<<i),limit);
    dfs(i+1,nums,sum,cur,limit);
}

int main()
{
    int n,s,v;
    while(cin >> n){
        cin >> s;
        vector<int> nums;
        for(int i=0;i<s;i++){
            cin >> v;
            nums.push_back(v);
        }
        res = best = 0;
        dfs(0,nums,0,0,n);
        for(int i=0;i<s;i++)
        if(res & (1<<i)) {
            printf("%d ",nums[i]);
        }
        printf("sum:%d\n",best);
    }
}
