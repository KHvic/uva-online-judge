#include <bits/stdc++.h>
using namespace std;

// idea: 
// perform dijkstra on graph and reverse graph
// this enable us to find the least weight path centered around any two middle node (for fulfilling the condition of cost < p)
// iterate all pair of middle node that fulfills the path requirement to find the heaviest edge
vector<int> dijkstra(int src, vector<vector<pair<int,int>>> graph){
    vector<int> dist(graph.size(),1e6);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int cur,cost;
        tie(cost,cur) = pq.top(); pq.pop();
        if(cost > dist[cur]) continue;
        for(auto& neigh : graph[cur]){
            int nextCost = cost+neigh.second;
            if(nextCost < dist[neigh.first]){
                dist[neigh.first] = nextCost;
                pq.push({nextCost,neigh.first});
            }
        }
    }
    return dist;
}

int main()
{
    int t;
    int n,m,s,e,p,a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d",&n,&m,&s,&e,&p);
        s--; e--;
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        vector<vector<pair<int,int>>> reverseGraph(n,vector<pair<int,int>>());
        queue<tuple<int,int,int>> edges; // there could duplicate a-b with difference c, need to try all
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&c);
            a--; b--;
            graph[a].push_back({b,c});
            reverseGraph[b].push_back({a,c});
            edges.push(make_tuple(a,b,c));
        }
        vector<int> costFromS = dijkstra(s,graph);
        vector<int> costFromE = dijkstra(e,reverseGraph);
        int best = -1;
        while(!edges.empty()){
            tie(a,b,c) = edges.front(); edges.pop();
            int totalCost = costFromS[a] + c + costFromE[b];
            if(totalCost <= p)
                best = max(best,c);
        }
        printf("%d\n",best);
    }
}
