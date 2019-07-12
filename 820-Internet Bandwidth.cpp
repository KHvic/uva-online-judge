#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> parent;

int n,s,t,c,a,b,v,tc=1,f;

// traverse spanning tree creating from s to t
void augment(int v, int minEdge){
    if (v==s) {
        f = minEdge; // record minEdge in global variable f
        return;
    } else if(parent[v] != -1){
        // recursive
        augment(parent[v], min(minEdge, graph[parent[v]][v]));
        // update backward and forward edge
        graph[parent[v]][v] -= f;
        graph[v][parent[v]] += f;
    }
}

int main()
{
    while(scanf("%d",&n),n){
        scanf("%d %d %d",&s,&t,&c);
        s--; t--;
        graph.assign(n,vector<int>(n));
        for(int i=0;i<c;i++){
            scanf("%d %d %d",&a,&b,&v);
            a--; b--;
            graph[a][b] += v;
            graph[b][a] += v;
        }
        int mf = 0;
        // edmond karp
        while(1) {
            f = 0;
            // BFS
            vector<int> dist(n, 1e7);
            dist[s] = 0; // track whether visited, can also use boolean
            queue<int> q;
            q.push(s);
            parent.assign(n,-1); // record BFS spanning tree
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u==t) break;
                for(int neigh=0; neigh<n; neigh++)
                    // has path and not visited yet
                    if(graph[u][neigh] > 0 && dist[neigh] == 1e7)
                        dist[neigh] = dist[u] + 1,
                        q.push(neigh),
                        parent[neigh] = u;
            }
            augment(t, 1e7); // backward path finding
            if(f == 0) break;
            mf += f;
        }
        printf("Network %d\n",tc++);
        printf("The bandwidth is %d.\n\n", mf);
    }
}
