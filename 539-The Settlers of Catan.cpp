#include <bits/stdc++.h>

using namespace std;

// brute force O(V*(E+V))
// a better way is to do a double dfs on each component O(V+E)

int ans;
void dfs(int cur,unordered_map<int,unordered_set<int>>& graph,int dist,unordered_set<string>& visited){
    ans = max(dist,ans);
    for(auto& n : graph[cur]){
        string key = to_string(cur) + "-" + to_string(n);
        string key2 = to_string(n) + "-" + to_string(cur);
        if(visited.count(key) || visited.count(key2)) continue;
        visited.insert(key); visited.insert(key2);
        dfs(n,graph,dist+1,visited);
        visited.erase(key); visited.erase(key2);
    }
}

int main()
{
    int n,m;
    int a,b;
    while(scanf("%d %d",&n,&m),n){
        ans = 0;
        unordered_map<int,unordered_set<int>> graph;
        for(int i=0;i<m;i++){
            cin >> a >> b;
            graph[a].insert(b);
            graph[b].insert(a);
        }
        int res = 0;
        unordered_set<string> visited;
        for(int i=0;i<n;i++)
            dfs(i,graph,0,visited);
        cout << ans << endl;
    }
}
