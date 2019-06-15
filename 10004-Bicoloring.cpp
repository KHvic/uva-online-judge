#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,l,a,b;
    while(scanf("%d",&n),n){
        scanf("%d",&l);
        unordered_map<int,unordered_set<int>> graph;
        for(int i=0;i<l;i++){
            scanf("%d %d",&a,&b);
            graph[a].insert(b);
            graph[b].insert(a);
        }
        queue<int> q; q.push(0);
        vector<int> color(n);
        color[0] = 1;
        bool isBipartile = true;
        while(!q.empty() & isBipartile){
            int cur = q.front(); q.pop();
            int curColor = color[cur];
            for(int neighbor : graph[cur]){
                if(color[neighbor] == curColor){
                    isBipartile = false;
                    break;
                } else if(color[neighbor] == 0){
                    // not yet colored
                    color[neighbor] = -curColor;
                    q.push(neighbor);
                }
            }
        }
        if(isBipartile) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
}
