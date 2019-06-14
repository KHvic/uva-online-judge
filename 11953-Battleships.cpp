#include<bits/stdc++.h>
using namespace std;
int t,n,tc=1;
string in;
vector<string> grid;
vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

void floodfill(int x,int y){
    if(x<0||y<0||x>=n||y>=n) return;
    if(grid[x][y] != '@' && grid[x][y] != 'x') return;
    grid[x][y] = '-';
    for(auto& dir : dirs){
        int nxtX = x+dir[0];
        int nxtY = y+dir[1];
        floodfill(nxtX,nxtY);
    }
}

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        grid.clear();
        for(int i=0;i<n;i++){
            cin >> in;
            grid.push_back(in);
        }
        int res = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 'x'){
                    res++;
                    floodfill(i,j);
                }
        printf("Case %d: %d\n",tc++,res);
    }
}
