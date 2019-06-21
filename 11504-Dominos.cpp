#include <bits/stdc++.h>
using namespace std;

int t,n,m,a,b,dfsCounter,numSCC;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> S;
vector<bool> visited;
vector<vector<int>> graph;
vector<int> componentId;

void tarjanSCC(int u){
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    visited[u] = true;
    S.push_back(u);
    for(auto& neigh : graph[u]){
        if(dfs_num[neigh] == -1)
            tarjanSCC(neigh);
        if(visited[neigh])
            dfs_low[u] = min(dfs_low[u],dfs_low[neigh]);
    }
    // is root of a SCC
    if(dfs_low[u] == dfs_num[u]){
        numSCC++;
        while(1){
            int top = S.back(); S.pop_back();
            componentId[top] = numSCC; // assign SCC idx to vertex
            visited[top] = false;
            if(u == top) break;
        }
    }
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        dfsCounter = numSCC = 0;
        dfs_num.assign(n,-1);
        dfs_low.assign(n,0);
        S.clear();
        visited.assign(n,false);
        graph.assign(n,vector<int>());
        componentId.assign(n,-1);
        
        for(int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            a--; b--;
            graph[a].push_back(b);
        }
        for(int i=0;i<n;i++)
            if(dfs_num[i] == -1){
                tarjanSCC(i);
            }
        // count indegree of each SCC
        vector<int> componentIndegree(numSCC,0);
        for(int i=0;i<n;i++)
            for(auto& neigh : graph[i]){
                // not within the same strongly connected component
                if(componentId[neigh] != componentId[i])
                    componentIndegree[componentId[neigh]]++;
            }
        int res = count(componentIndegree.begin(),componentIndegree.end(),0);
        printf("%d\n",res);
    }
}
