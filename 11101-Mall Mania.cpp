#include <bits/stdc++.h>
using namespace std;

// array is much faster
bool visited[2001][2001], targets[2001][2001];
vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
int main()
{
    int p,x,y;
    while(scanf("%d",&p),p!=0){
        memset(visited,0,sizeof visited);
        memset(targets,0,sizeof targets);
        queue<pair<int,int>> bfs;
        for(int i=0;i<p;i++){
            scanf("%d %d",&x,&y);
            bfs.push({x,y});
            visited[x][y] = true;
        }
        scanf("%d",&p);
        for(int i=0;i<p;i++){
            scanf("%d %d",&x,&y);
            targets[x][y] = true;
        }
        int steps=0;
        bool found = false;
        while(!found){
            int len=bfs.size();
            for(int i=0;i<len && !found;i++){
                tie(x,y) = bfs.front(); bfs.pop();
                if(targets[x][y]) found = true;
                else {
                    for(auto& dir : dirs){
                        int nextX = x+dir[0], nextY = y+dir[1];
                        if(nextX<0||nextX>2000||nextY<0||nextY>2000) continue;
                        if(visited[nextX][nextY]) continue;
                        visited[nextX][nextY] = true;
                        bfs.push({nextX,nextY});
                    }
                }
            }
            if(!found) steps++;
        }
        printf("%d\n",steps);
    }
}
