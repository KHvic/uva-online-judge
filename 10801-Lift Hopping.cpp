#include <bits/stdc++.h>

using namespace std;
// state: current level, current elevator
// we can also use a single state space by building a graph that merges the two state
int main()
{
    int n,k,t,v;
    string in;
    while(scanf("%d %d",&n,&k) != EOF){
        vector<int> elevator_time;
        vector<vector<int>> dist(100,vector<int>(5,1e7));
        for(int i=0;i<5;i++)
            dist[0][i] = 0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            elevator_time.push_back(t);
        }
        cin.ignore();
        // elevator x can go to what level?
        vector<vector<int>> edges(n,vector<int>()); // elevator to level
        vector<vector<int>> floorElevator(100,vector<int>()); // level to elevator
        for(int i=0;i<n;i++){
            getline(cin,in);
            istringstream iss(in);
            while(iss >> v){
                edges[i].push_back(v);
                floorElevator[v].push_back(i);
                if(v == 0){
                    pq.push(make_tuple(0,0,i));
                }
            }
        }
        while(!pq.empty()){
            int cost,level,elevator;
            tie(cost,level,elevator) = pq.top(); pq.pop();
            if(cost > dist[level][elevator]) continue;
            // use same elevator to go to other floors
            for(int neigh : edges[elevator]){
                int nextCost = cost + abs(level-neigh)*elevator_time[elevator];
                if(nextCost < dist[neigh][elevator]){
                    pq.push(make_tuple(nextCost,neigh,elevator));
                    dist[neigh][elevator] = nextCost;
                }
            }
            // switch to other elevator
            for(int otherElevator : floorElevator[level]){
                int nextCost = cost + 60;
                if(nextCost < dist[level][otherElevator]){
                    pq.push(make_tuple(nextCost,level,otherElevator));
                    dist[level][otherElevator] = nextCost;
                }
            }
        }
        int res = 1e7;
        for(int i=0;i<5;i++) res = min(res,dist[k][i]);
        if(res >= 1e7) printf("IMPOSSIBLE\n");
        else printf("%d\n",res);
    }
}
