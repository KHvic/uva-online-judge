#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int>& nums, int cur, vector<bool>& used, bool first){
    bool allUsed = true;
    for(int i=0;i<5;i++){
        if(used[i]) continue;
        allUsed = false;
        used[i] = true;
        if(dfs(nums,cur+nums[i],used,false)) return true;
        else if(!first && dfs(nums,cur-nums[i],used,false)) return true;
        else if(!first && dfs(nums,cur*nums[i],used,false)) return true;
        used[i] = false;
    }
    if(allUsed) return cur == 23;
    else return false;
}

int main()
{
    int a,b,c,d,e;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&e),a||b||c||d||e){
        vector<int> nums = {a,b,c,d,e};
        vector<bool> used(5);
        cout << (dfs(nums,0,used,true) ? "Possible" : "Impossible") << endl;
    }
}
