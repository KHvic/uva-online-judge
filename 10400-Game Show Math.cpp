#include <bits/stdc++.h>
using namespace std;

int t,n,target,v;
vector<int> nums;
vector<unordered_set<int>> visited;
vector<char> ops;

bool dfs(int idx,int val){
    if(val > 32000 || val < -32000) return false;
    if(idx == n) return val == target;
    if(visited[idx].count(val)) return false; // already visited return false

    visited[idx].insert(val);
    if(dfs(idx+1,val+nums[idx])){
        ops.push_back('+');
        return true;
    }
    if(dfs(idx+1,val-nums[idx])){
        ops.push_back('-');
        return true;
    }
    if(dfs(idx+1,val*nums[idx])){
        ops.push_back('*');
        return true;
    }
    if((val%nums[idx]) == 0 && dfs(idx+1,val/nums[idx])){
        ops.push_back('/');
        return true;
    }
    return false;
}

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        visited = vector<unordered_set<int>>(n);
        ops.clear();
        nums.clear();
        for(int i=0;i<n;i++){
            cin >> v;
            nums.push_back(v);
        }
        cin >> target;
        if(dfs(1,nums[0])){
            for(int i=0;i<n;i++){
                cout << nums[i];
                if(i+1 != n) cout << ops[ops.size()-1-i];
                else printf("=%d\n",target);
            }
        } else printf("NO EXPRESSION\n");
    }
}
