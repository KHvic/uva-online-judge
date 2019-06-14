#include<bits/stdc++.h>
using namespace std;
int r,c,sx,sy,tc=1;
char land;
string in;
vector<string> grid;
vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

int floodfill(int x,int y){
    if(x<0||y<0||x>=r||y>=c) return 0;
    if(grid[x][y] != land) return 0;
    grid[x][y] = ';';
    int cnt = 1;
    for(auto& dir : dirs){
        int nxtX = x+dir[0];
        int nxtY = (y+dir[1]+c)%c;
        cnt += floodfill(nxtX,nxtY);
    }
    return cnt;
}

int main()
{
    while(scanf("%d %d",&r,&c) != EOF){
        grid.clear();
        for(int i=0;i<r;i++){
            cin >> in;
            grid.push_back(in);
        }
        cin >> sx >> sy;
        land = grid[sx][sy];
        floodfill(sx,sy);
        int best = 0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            if(grid[i][j] == land){
                best = max(best,floodfill(i,j));
            }
        printf("%d\n",best);
    }
}
