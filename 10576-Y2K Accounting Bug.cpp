#include <bits/stdc++.h>
using namespace std;
int res;

bool dfs(vector<int>& history,int s,int d,int idx,int cur){
    if(idx==12){
        res = 0;
        for(auto& i : history) res+=i;
        // first result is always the optimal (greedy) because we always choose s first
        return true;
    }
    // choose s first
    if(idx>4) cur-=history[idx-5];
    if(idx<4 || cur+s < 0){
        history.push_back(s);
        // pruning
        if(dfs(history,s,d,idx+1,cur+s)) return true;
        history.pop_back();
    }
    if(idx<4 || cur-d < 0){
        history.push_back(-d);
        if(dfs(history,s,d,idx+1,cur-d)) return true;
        history.pop_back();
    }
    return false;
}

int main()
{
    int s,d;
    while(scanf("%d %d",&s,&d) != EOF){
        res = INT_MIN;
        vector<int> history;
        dfs(history,s,d,0,0);
        if(res < 0) cout<<"Deficit"<<endl;
        else cout<<res<<endl;
    }
}
