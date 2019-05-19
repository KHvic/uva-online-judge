#include <bits/stdc++.h>
using namespace std;
bool found = false;

void dfs(int idx,vector<int>& nums,int sum,vector<int>& cur,int t){
    if(sum == t){
        found = true;
        for(auto& v : cur){
            cout << v;
            if(&v == &cur.back()) cout << endl;
            else cout << "+";
        }
        return;
    }
    if(idx >= nums.size() || sum > t) return;

    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i] == nums[i-1]) continue;
        cur.push_back(nums[i]);
        dfs(i+1,nums,sum+nums[i],cur,t);
        cur.pop_back();
    }
}

int main()
{
    int t,n,v;
    while(scanf("%d %d",&t,&n),t||n){
        vector<int> nums;
        vector<int> cur;
        for(int i=0;i<n;i++){
            cin >> v;
            nums.push_back(v);
        }
        found = false;
        printf("Sums of %d:\n",t);
        dfs(0,nums,0,cur,t);
        if(!found) printf("NONE\n");
    }
}
