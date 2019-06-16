#include<bits/stdc++.h>
using namespace std;
int n,a,b;
vector<vector<int>> graph;
vector<int> colors;

bool dfs(int cur,int color){
    if(colors[cur] != 0) return colors[cur] == color;
    colors[cur] = color;
    for(auto& neigh : graph[cur]){
        if(!dfs(neigh,-color)) return false;
    }
    return true;
}

int main()
{
    while(scanf("%d",&n),n){
        graph.assign(n+1,vector<int>());
        colors.assign(n+1,0);
        while(scanf("%d %d",&a,&b),(a+b)!=0){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool bipartile = true;
        for(int i=1;i<=n && bipartile;i++)
            if(colors[i] == 0){
                bipartile = dfs(i,1);
            }
        if(bipartile) printf("YES\n");
        else printf("NO\n");
    }
}
