#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<bool> visited;
unordered_map<int,unordered_set<int>> graph;

void dfs(int cur,stack<int>& topo){
    visited[cur] = true;
    for(auto& successor : graph[cur])
        if(!visited[successor])
            dfs(successor,topo);
    topo.push(cur);
}

int main()
{
    while(scanf("%d %d",&n,&m),(n+m)!=0){
        visited.assign(n+1,false);
        graph.clear();
        for(int i=0;i<m;i++){
            cin >> a >> b;
            graph[a].insert(b);
        }
        stack<int> topological;
        for(int i=1;i<=n;i++)
            if(!visited[i])
                dfs(i,topological);
        while(!topological.empty()){
            printf("%d",topological.top());
            topological.pop();
            if(topological.empty()) printf("\n");
            else printf(" ");
        }
    }
}
