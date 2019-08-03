#include <bits/stdc++.h>

using namespace std;
unordered_map<int,unordered_map<int,int>> graph;
vector<int> parents;
int k,p,x,v,f;

void augment(int cur,int minEdge){
    if(cur == 0){
        f = minEdge;
        return;
    } else if(parents[cur] != -1){
        int par = parents[cur];
        augment(par,min(minEdge,graph[par][cur]));
        graph[par][cur] -= f;
        graph[cur][par] += f;
    }
}

int main() {
    while(scanf("%d %d",&k,&p),(k+p)!=0){
        graph.clear();
        // 0 - source
        // 1 - sink
        // 2-(k+2) - categories
        // > k+2 - problems
        int problemsNeeded = 0;
        for(int i=0;i<k;i++){
            scanf("%d",&v);
            graph[0][2+i] = v;
            problemsNeeded += v;
        }
        for(int i=0;i<p;i++){
            scanf("%d",&x);
            while(x--){
                scanf("%d",&v);
                v--;
                graph[2+v][2+k+i] = 1; // category to problem
            }
            graph[2+k+i][1] = 1; // problem to sink
        }
        // edmonds karp
        int mf=0;
        while(1){
            f = 0;
            vector<bool> visited(2+k+p);
            queue<int> bfs;
            parents.assign(2+k+p,-1);
            bfs.push(0);
            visited[0] = true;
            while(!bfs.empty()){
                int cur = bfs.front(); bfs.pop();
                if(cur == 1) break;
                for(auto& neigh : graph[cur]){
                    if(neigh.second>0 && !visited[neigh.first]){
                        parents[neigh.first] = cur;
                        visited[neigh.first] = true;
                        bfs.push(neigh.first);
                    }
                }
            }
            augment(1,1e7);
            if(f==0) break;
            mf += f;
        }
        if(mf != problemsNeeded) printf("0\n");
        else {
            printf("1\n");
            for(int i=0;i<k;i++){
                bool first = true;
                for(auto& neigh : graph[2+i]){
                    // check backedge
                    if(graph[neigh.first][2+i]>0){
                        if(!first) printf(" ");
                        first = false;
                        printf("%d",neigh.first-k-1);
                    }
                }
                printf("\n");
            }
        }
    }
}
