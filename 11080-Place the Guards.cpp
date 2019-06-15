#include<bits/stdc++.h>
using namespace std;

int cntColor1 = 0;
int cntColor2 = 0;
vector<int> color;
unordered_map<int,unordered_set<int>> graph;

bool dfs(int n, int col){
    if(color[n] != 0) return color[n] == col;
    color[n] = col;
    if(col == 1) cntColor1++;
    else cntColor2++;
    for(auto& neigh : graph[n]){
        if(!dfs(neigh,-col)) return false;
    }
    return true;
}

int main()
{
    int t,n,m,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        color.assign(n,0);
        graph.clear();
        for(int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            graph[a].insert(b);
            graph[b].insert(a);
        }
        bool bipartile = true;
        int res = 0;
        for(int i=0;i<n && bipartile;i++){
            if(color[i] == 0){
                cntColor1 = cntColor2 = 0;
                bipartile = dfs(i,1);
                // foreach component, take less count color
                res += max(1,min(cntColor1,cntColor2));
            }
        }
        if(bipartile) printf("%d\n",res);
        else printf("%d\n",-1);
    }
}
