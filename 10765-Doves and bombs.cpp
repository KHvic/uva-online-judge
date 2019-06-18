#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
unordered_map<int,unordered_set<int>> graph;
vector<int> dfs_parent;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren, connectedComponent;

void articulationPoint(int u){
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++;

    for(int neigh : graph[u]){
        if(dfs_num[neigh] == -1){
            dfs_parent[neigh] = u;
            if(u == dfsRoot) rootChildren++;

            articulationPoint(neigh);
            // increase count, because this is an articulation point to neigh
            if(dfs_low[neigh] >= dfs_num[u])
                articulation_vertex[u]++;

            dfs_low[u] = min(dfs_low[neigh],dfs_low[u]);
        } else if(neigh != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u],dfs_num[neigh]);
        }
    }
}

int main()
{
    while(scanf("%d %d",&n,&m),(n+m)!=0){
        dfsNumberCounter = 0;
        dfs_parent.assign(n,-1);
        articulation_vertex.assign(n,0);
        dfs_low.assign(n,0);
        dfs_num.assign(n,-1);
        graph.clear();
        int connectedComponent = 0;

        while(scanf("%d %d",&a,&b),!(a==-1&&b==-1)){
            graph[a].insert(b);
            graph[b].insert(a);
        }

        for(int i=0;i<n;i++)
        if(dfs_num[i] == -1){
            connectedComponent++;
            rootChildren = 0;
            dfsRoot = i;
            articulationPoint(i);
            articulation_vertex[i] = rootChildren - 1;
        }
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++)
            res.push_back({articulation_vertex[i]+connectedComponent,i});

        sort(res.begin(),res.end(),[](pair<int,int>& a, pair<int,int>& b){
                if(a.first == b.first) return a.second < b.second;
                return a.first > b.first;
             });

        for(int i=0;i<m;i++)
            printf("%d %d\n",res[i].second,res[i].first);
        printf("\n");
    }
}
