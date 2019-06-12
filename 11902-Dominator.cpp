#include <bits/stdc++.h>
using namespace std;

int n;
bool res[101][101], graph[101][101], visited[101];
void dfs(int cur, int dest) {
    if(cur == dest) return;
    visited[cur] = true;
    for(int i = 0; i < n; i++) {
        if(graph[cur][i] && !visited[i]) {
            dfs(i, dest);
        }
    }
}
int main() {
    int t,tc=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        // construct graph
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &graph[i][j]);
        int reachable[105] = {};
        memset(visited,0,sizeof visited);
        // dfs from vertex 0 and mark reachable vertex
        dfs(0, -1);
        for(int i=0; i<n; i++)
            reachable[i]=visited[i];
        
        for(int x=0; x<n; x++) {
            memset(visited,0,sizeof visited);
            // try to put x as the dominator, dfs can't get pass x
            dfs(0, x);
            for(int y=0; y<n; y++)
                // if y is previously reachable, but not anymore if we terminate at x
                // then x is a dominator of y
                if(reachable[y] && !visited[y])
                    res[x][y] = true;
                else
                    res[x][y] = false;
            res[x][x] = reachable[x];
        }

        printf("Case %d:\n",tc++);
        printf("+");
        cout << string(n*2-1,'-');
        printf("+\n");
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                printf("|%c", res[i][j] ? 'Y' : 'N');
            }
            printf("|\n");
            printf("+");
            cout << string(n*2-1,'-');
            printf("+\n");
        }
    }
    return 0;
}
