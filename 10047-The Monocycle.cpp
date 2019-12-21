#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};

int main() {
    int n,m,tc=1;
    int x,y,color,d;
    char c;
    while(scanf("%d %d",&n,&m),(n+m)){
        if(tc > 1) printf("\n");
        vector<vector<char>> grid;
        int sx, sy, tx, ty;
        for(int i=0;i<n;i++) {
            vector<char> row;
            for(int j=0;j<m;j++) {
                cin >> c;
                row.push_back(c);
                if(c == 'T') {
                    tx = i, ty = j;
                } else if(c == 'S') {
                    sx = i, sy = j;
                }
            }
            grid.push_back(row);
        }
        // state: x,y,color,dir
        vector<vector<vector<vector<bool>>>> visited(n,vector<vector<vector<bool>>>(m, vector<vector<bool>>(5,vector<bool>(4))));
        visited[sx][sy][0][0] = true;
        queue<vector<int>> bfs;
        bfs.push({sx,sy,0,0});

        int steps = 0;
        bool solved = false;
        while(!bfs.empty() && !solved) {
            int len = bfs.size();
            for(int i=0;i<len;i++) {
                x = bfs.front()[0], y = bfs.front()[1], color = bfs.front()[2], d = bfs.front()[3];
                bfs.pop();
                if(x == tx && y == ty && color == 0) {
                    solved = true;
                    break;
                }
                // switch direction
                for (int lr : {1,3}) {
                    int nextD = (d+lr) % 4;
                    if(!visited[x][y][color][nextD])
                        visited[x][y][color][nextD] = true, bfs.push({x,y,color,nextD});
                }
                // forward move
                int nextX = x+dirs[d][0], nextY = y+dirs[d][1], nextColor = (color+1)%5;
                if(nextX <0 || nextX >= n || nextY < 0 || nextY >= m) continue;
                if(grid[nextX][nextY] == '#' || visited[nextX][nextY][nextColor][d]) continue;
                visited[nextX][nextY][nextColor][d] = true, bfs.push({nextX,nextY,nextColor,d});
            }
            if(!solved) steps++;
        }
        printf("Case #%d\n", tc++);
        if (solved) printf("minimum time = %d sec\n", steps);
        else printf("destination not reachable\n");
    }
}
