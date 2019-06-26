#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,r,q,s,e,c;
    vector<int> fuel_prices;
    scanf("%d %d",&n,&r);
    for(int i=0;i<n;i++){
        cin >> s;
        fuel_prices.push_back(s);
    }
    // neighNode, fuel cost pair
    vector<vector<pair<int,int>>> graph(n);
    for(int i=0;i<r;i++){
        cin >> s >> e >> c;
        graph[s].push_back({e,c});
        graph[e].push_back({s,c});
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> c >> s >> e;
        vector<vector<int>> dist(n,vector<int>(c+1,1e7));
        // tuple <cost,cur-node,fuel-left>
        // state space modelling of <cur-location, fuel-left>
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,s,0});
        dist[s][0] = 0;
        int leastDist = 1e7;
        
        // dijkstra algorithm
        while(!pq.empty()){
            int curCost,cur,fuelLeft;
            tie(curCost,cur,fuelLeft) = pq.top(); pq.pop();
            if(curCost > dist[cur][fuelLeft]) continue; // avoid processing
            if(cur == e)
                leastDist = min(leastDist, curCost);
            // add fuel at station
            if(fuelLeft < c){
                int nextFuelLeft = fuelLeft + 1;
                int nextCost = curCost + fuel_prices[cur];
                if(nextCost < dist[cur][nextFuelLeft]){
                    dist[cur][nextFuelLeft] = nextCost;
                    tuple<int,int,int> nextState = {nextCost,cur,nextFuelLeft};
                    pq.push(nextState);
                }
            }
            // traverse to neighbor
            for(pair<int,int> neigh : graph[cur]){
                if(fuelLeft >= neigh.second){
                    int nextFuelLeft = fuelLeft - neigh.second;
                    if(curCost < dist[neigh.first][nextFuelLeft]){
                        dist[neigh.first][nextFuelLeft] = curCost;
                        tuple<int,int,int> nextState = {curCost,neigh.first,nextFuelLeft};
                        pq.push(nextState);
                    }
                }
            }
        }
        if(leastDist >= 1e7) printf("impossible\n");
        else printf("%d\n",leastDist);
    }
}
