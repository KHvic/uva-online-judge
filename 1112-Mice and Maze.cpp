#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc,n,e,t,m,a,b,v;
    cin >> tc;
    while(tc--){
        cin >> n >> e >> t >> m;
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<m;i++){
            cin >> a >> b >> v;
            graph[b-1].push_back({a-1,v});
        }
        vector<int> dist(n,1e7);
        e--;
        dist[e] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,e});
        while(!pq.empty()){
            int cost,cur;
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
        int res = 0;
        for(auto& shortestTime : dist)
            if(shortestTime <= t)
                res++;
        printf("%d\n",res);
        if(tc) printf("\n");
    }
}
