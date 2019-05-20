#include <bits/stdc++.h>
using namespace std;

int ans=0;

// prune impossible graph/node with single dfs
void prune(int idx,unordered_map<int,set<int>>& graph,
         vector<bool>& visited){
    if(!visited[idx]) return;
    visited[idx] = false; // allow visit in next dfs
    for(auto& neigh : graph[idx])
        prune(neigh,graph,visited);
}

void dfs(int idx,unordered_map<int,set<int>>& graph,
         vector<bool>& visited,vector<int>& cur){
    if(idx == visited.size()-1){
        ans++;
        for(auto& v : cur){
            cout << (v+1);
            if(&v == &cur.back()) cout << endl;
            else cout << " ";
        }
        return;
    }
    for(auto& neigh : graph[idx]){
        if(!visited[neigh]){
            visited[neigh] = true;
            cur.push_back(neigh);
            dfs(neigh,graph,visited,cur);
            visited[neigh] = false;
            cur.pop_back();
        }
    }
}

int main()
{
    int n,tc=1;
    int a,b;
    while(cin >> n){
        unordered_map<int,set<int>> graph;
        vector<bool> visited(n,true);
        vector<int> cur(1,0);
        ans=0;
        while(scanf("%d %d",&a,&b),a||b){
            graph[a-1].insert(b-1);
            graph[b-1].insert(a-1);
        }
        printf("CASE %d:\n",tc++);
        prune(n-1,graph,visited);
        if(!visited[0]) {
            visited[0] = true;
            dfs(0,graph,visited,cur);
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n",ans,n);
    }
}
