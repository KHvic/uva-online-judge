#include<bits/stdc++.h>
using namespace std;

int n,a,b;
string in;
int dfsNumberCounter, dfsRoot, rootChildren;
vector<int> dfs_low; // lowest visitable node's dfs_num
vector<int> dfs_num; // iteration counter
vector<bool> articulation_vertex; // is a articulation vertex
vector<int> dfs_parent; // track parent
unordered_map<int,unordered_set<int>> graph;
void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(int neigh : graph[u]){
        // explored to unvisited: a tree edge
        if(dfs_num[neigh] == -1){
            dfs_parent[neigh] = u;
            if(u == dfsRoot) rootChildren++; // special case, count children of root

            articulationPointAndBridge(neigh);

            // for articulation point
            if(dfs_low[neigh] >= dfs_num[u]){
                articulation_vertex[u] = true;
            }

            // for bridge
            // if (dfs_low[v.first] > dfs_num[u])
            //    printf(" Edge (%d, %d) is a bridge\n", u, v.first);
            dfs_low[u] = min(dfs_low[u], dfs_low[neigh]); // update dfs_low of current node - bidirectional edge
        }
        // a back edge and not direct cycle: explored to explored
        else if (neigh != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[neigh]); // next node using backedge has smaller dfs_num?
    }
}

int main()
{
    while(scanf("%d",&n),n){
        cin.ignore();
        dfs_low.assign(n,0);
        dfs_num.assign(n,-1);
        dfs_parent.assign(n,0);
        articulation_vertex.assign(n,false);
        graph.clear();
        dfsNumberCounter = 0;
        while(getline(cin,in), in!="0"){
            istringstream iss(in);
            iss >> a;
            a--;
            while(iss >> b){
                b--;
                graph[a].insert(b);
                graph[b].insert(a);
            }
        }
        for(int i=0;i<n;i++)
        if(dfs_num[i] == -1){
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
        }
        int res = 0;
        for(auto v : articulation_vertex)
            if(v) res++;
        printf("%d\n",res);
    }
}
