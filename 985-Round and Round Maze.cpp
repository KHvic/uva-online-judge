#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};

int main() {
    int n,m;
    string in;
    vector<int> cIdx(26);
    cIdx['N'-'A'] = 0, cIdx['E'-'A'] = 1, cIdx['S'-'A'] = 2, cIdx['W'-'A'] = 3;
    while(scanf("%d %d",&n,&m) == 2) {
        vector<vector<vector<bool>>> maze(n,vector<vector<bool>>(m,vector<bool>(4)));
        vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(4)));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 && j==m-1) continue;
                cin >> in;
                for(auto c : in)
                    maze[i][j][cIdx[c-'A']] = true;
            }
        }
        int steps = 0;
        queue<vector<int>> bfs;
        bfs.push({0,0});
        visited[0][0][0] = true;
        bool solved = false;
        while(!bfs.empty() && !solved) {
            int len = bfs.size();
            for(int i=0;i<len;i++) {
                vector<int> cur = bfs.front(); bfs.pop();
                if(cur[0] == n-1 && cur[1] == m-1) {
                    solved = true;
                    break;
                }
                for(int j=0;j<4;j++){
                    if(!maze[cur[0]][cur[1]][j]) continue;
                    int mod = (j+steps)%4;
                    int next_x = dirs[mod][0] + cur[0], next_y = dirs[mod][1] + cur[1];
                    if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
                    int next_t = (steps+1)%4;
                    if(visited[next_x][next_y][next_t]) continue;
                    visited[next_x][next_y][next_t] = true;
                    bfs.push({next_x,next_y});
                }
            }
            if(!solved) steps++;
        }
        if(solved) printf("%d\n",steps);
        else printf("no path to exit\n");
    }
}
