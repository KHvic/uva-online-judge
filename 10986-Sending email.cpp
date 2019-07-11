#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,s,e,a,b,w,tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&n,&m,&s,&e);
        vector<vector<pair<int,int>>> graph(n);
        vector<int> dist(n,1e7);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&w);
            graph[a].push_back({b,w});
            graph[b].push_back({a,w});
        }
        // dijkstra
        dist[s] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            int cost, cur;
            tie(cost,cur) = pq.top(); pq.pop();
            if(cost > dist[cur]) continue;
            for(auto& neigh : graph[cur]){
                int nextCost = cost + neigh.second;
                if(nextCost < dist[neigh.first]){
                    pq.push({nextCost,neigh.first});
                    dist[neigh.first] = nextCost;
                }
            }
        }
        if(dist[e] >= 1e7) printf("Case #%d: unreachable\n",tc++);
        else printf("Case #%d: %d\n",tc++,dist[e]);
    }
}
