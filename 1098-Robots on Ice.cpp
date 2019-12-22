#include <bits/stdc++.h>
using namespace std;

int n,m,total,tc=1;
vector<pair<int,int>> t;
vector<int> checkpoints;
vector<vector<bool>> visited,visited2;
vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

// count reachable
int dfs2(int x, int y){
    if(x<0||y<0||x>=n||y>=m) return 0;
    if(visited[x][y] || visited2[x][y]) return 0;
    visited2[x][y] = true;
    int sum = 1;
    for(auto& dir : dirs){
        int nextX = dir[0] + x, nextY = dir[1] + y;
        sum += dfs2(nextX, nextY);
    }
    return sum;
}

int dfs(int x, int y, int steps){
    if(x<0||y<0||x>=n||y>=m) return 0;
    if(visited[x][y]) return 0;
    else if(steps == checkpoints[3]) return 1;
    else if(steps == checkpoints[2]) {
        if(x!=t[2].first || y!=t[2].second) return 0;
    } else if(steps == checkpoints[1]) {
        if(x!=t[1].first || y!=t[1].second) return 0;
    } else if(steps == checkpoints[0]) {
        if(x!=t[0].first || y!=t[0].second) return 0;
    } else {
        for(int i=0;i<4;i++) {
            if(x==t[i].first && y==t[i].second)
                return 0;
            // manhanttan check if can reach on time
            int dist = abs(x-t[i].first) + abs(y-t[i].second);
            int turnLeft = checkpoints[i] - steps;
            if(turnLeft > 0 && turnLeft < dist) return 0;
        }
    }
    // do another dfs from last node to check if we can reach all nodes
    visited2.assign(n,vector<bool>(m));
    visited2[x][y] = true;
    int cnt = dfs2(0,1);
    if(cnt != total-steps) {
        return 0;
    }
    // go all directions
    visited[x][y] = true;
    int path = 0;
    for(auto& dir : dirs){
        int nextX = dir[0] + x, nextY = dir[1] + y;
        path += dfs(nextX, nextY, steps+1);
    }
    visited[x][y] = false;
    return path;
}

int main() {
    while(scanf("%d %d",&n,&m),(n+m)){
        t.assign(3, {0,0});
        scanf("%d %d %d %d %d %d", &t[0].first, &t[0].second,
              &t[1].first, &t[1].second, &t[2].first, &t[2].second);
        t.push_back(make_pair(0,1));
        visited.assign(n,vector<bool>(m,false));
        total = n*m;
        checkpoints = {total/4,total/2,3*total/4,n*m};
        printf("Case %d: %d\n",tc++,dfs(0,0,1));
    }
}
