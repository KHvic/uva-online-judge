#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0,1},{1,0},{1,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};

void dfs(int x,int y,vector<string>& grid){
    if(x<0||y<0||x>=grid.size()||y>=grid.size()) return;
    if(grid[x][y] != '1') return;
    grid[x][y] = '0';
    for(auto& dir : dirs){
        int nextX = x+dir[0];
        int nextY = y+dir[1];
        dfs(nextX,nextY,grid);
    }
}

int main()
{
    int n,tc=1;
    string in;
    while(cin >> n){
        vector<string> grid;
        for(int i=0;i<n;i++){
            cin >> in;
            grid.push_back(in);
        }
        int res = 0;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j] == '1'){
                res++;
                dfs(i,j,grid);
            }
        printf("Image number %d contains %d war eagles.\n",tc++,res);
    }
}
