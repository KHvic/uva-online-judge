#include <bits/stdc++.h>

using namespace std;

int n, m;
string a, b;
unordered_map<string,int> nameToIdx;
vector<string> idxToName;
unordered_map<int,unordered_set<int>> graph;
vector<int> dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (auto neigh : graph[u]) {
        if (dfs_num[neigh] == -1)
            tarjanSCC(neigh);
        if (visited[neigh]) // condition for update, already in stack
            dfs_low[u] = min(dfs_low[u], dfs_low[neigh]);
    }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
        // printf("SCC %d:", ++numSCC); // this part is done after recursion
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            cout << idxToName[v];
            if (u == v) {
                printf("\n");
                break;
            } else printf(", ");
        }
    }
}

int main(){
    int tc=1;
    while(scanf("%d %d",&n,&m),(n+m)!=0){
        if(tc>1) printf("\n");
        graph.clear();
        idxToName.clear();
        nameToIdx.clear();
        dfs_num.assign(n, -1);
        dfs_low.assign(n, 0);
        visited.assign(n, 0);
        S.clear();
        dfsNumberCounter = numSCC = 0;
        int nodeIdx = 0;
        for(int i=0;i<m;i++){
            cin >> a >> b;
            if(!nameToIdx.count(a)){
                nameToIdx[a] = nodeIdx++;
                idxToName.push_back(a);
            }
            if(!nameToIdx.count(b)){
                nameToIdx[b] = nodeIdx++;
                idxToName.push_back(b);
            }
            int idxA = nameToIdx[a], idxB = nameToIdx[b];
            graph[idxA].insert(idxB);
        }
        printf("Calling circles for data set %d:\n",tc++);
        for (int i=0;i<n && m;i++)
            if (dfs_num[i] == -1)
                tarjanSCC(i);
    }
}
