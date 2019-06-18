#include<bits/stdc++.h>
using namespace std;

int n,a,b;
string in;
int dfsNumberCounter, dfsRoot, rootChildren;
vector<int> dfs_low; // lowest visitable node's dfs_num
vector<int> dfs_num; // iteration counter
vector<int> dfs_parent; // track parent
unordered_map<int,unordered_set<int>> graph;
set<pair<int,int>> bridges;
void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(int neigh : graph[u]){
        // explored to unvisited: a tree edge
        if(dfs_num[neigh] == -1){
            dfs_parent[neigh] = u;

            articulationPointAndBridge(neigh);

            // for bridge
            if (dfs_low[neigh] > dfs_num[u]){
                if(u < neigh) bridges.insert({u,neigh});
                else bridges.insert({neigh,u});
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[neigh]); // update dfs_low of current node - bidirectional edge
        }
        // a back edge and not direct cycle: explored to explored
        else if (neigh != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[neigh]); // next node using backedge has smaller dfs_num?
    }
}

int main()
{
    while(scanf("%d",&n) != EOF){
        cin.ignore();
        dfs_low.assign(n,0);
        dfs_num.assign(n,-1);
        dfs_parent.assign(n,0);
        graph.clear();
        bridges.clear();
        dfsNumberCounter = 0;
        for(int i=0;i<n;i++){
            getline(cin,in);
            istringstream iss(in);
            iss >> a;
            iss >> in;
            while(iss >> b){
                graph[a].insert(b);
                graph[b].insert(a);
            }
        }
        for(int i=0;i<n;i++)
        if(dfs_num[i] == -1){
            dfsRoot = i;
            articulationPointAndBridge(i);
        }
        printf("%d critical links\n",bridges.size());
        for(auto& p : bridges){
            printf("%d - %d\n",p.first,p.second);
        }
        printf("\n");
    }
}
