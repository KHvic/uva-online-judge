#include <bits/stdc++.h>

using namespace std;

int dirs[][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    int t,n,m,v;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> v;
            grid[i][j] = v;
        }
        // dijkstra
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e7));
        dist[0][0] = grid[0][0];
        pq.push(make_tuple(grid[0][0],0,0));

        while(!pq.empty()){
            int cost,x,y;
            tie(cost,x,y) = pq.top(); pq.pop();
            if(cost > dist[x][y]) continue;
            for(auto dir : dirs){
                int nextX = dir[0]+x;
                int nextY = dir[1]+y;
                if(nextX<0||nextY<0||nextX>=n||nextY>=m) continue;
                if(cost+grid[nextX][nextY] < dist[nextX][nextY]){
                    dist[nextX][nextY] = cost+grid[nextX][nextY];
                    pq.push(make_tuple(dist[nextX][nextY],nextX,nextY));
                }
            }
        }
        cout << dist[n-1][m-1] << endl;
    }
}
