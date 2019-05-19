#include <bits/stdc++.h>
using namespace std;
int start,last;

bool dfs(int idx,int n,int cur,vector<bool>& used,vector<pair<int,int>>& domi){
    if(idx == n){
        return cur == last;
    }
    for(int i=0;i<domi.size();i++){
        if(used[i]) continue;
        used[i] = true;
        if(cur == domi[i].first && dfs(idx+1,n,domi[i].second,used,domi))
            return true;
        if(cur == domi[i].second && dfs(idx+1,n,domi[i].first,used,domi))
            return true;
        used[i] = false;
    }
    return false;
}

int main()
{
    int n,m,l,r;
    while(scanf("%d",&n),n){
        cin >> m;
        cin >> l >> start;
        cin >> last >> r;
        vector<pair<int,int>> domi;
        vector<bool> used(m);
        for(int i=0;i<m;i++){
            cin >> l >> r;
            domi.push_back({l,r});
        }
        if(dfs(0,n,start,used,domi)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
