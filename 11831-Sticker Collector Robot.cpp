#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,s;
    char c;
    string commands;
    int x,y;
    int face = 0;
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    while(scanf("%d %d %d",&n,&m,&s),(n+m+s)!=0){
        vector<vector<char>> grid;
        for(int i=0;i<n;i++){
            vector<char> row;
            for(int j=0;j<m;j++){
                cin >> c;
                if(isalpha(c)){
                    x=i, y=j;
                    if(c == 'N') face=0;
                    else if(c == 'S') face=2;
                    else if(c == 'L') face=1;
                    else face=3;
                }
                row.push_back(c);
            }
            grid.push_back(row);
        }
        int res = 0;
        cin >> commands;
        for(auto& ch : commands){
            if(ch == 'E') face = (face-1+4)%4;
            else if(ch == 'D') face = (face+1)%4;
            else {
                int nextX = x+dirs[face][0];
                int nextY = y+dirs[face][1];
                if(nextX<0 || nextX>=n || nextY<0 || nextY>=m) continue;
                if(grid[nextX][nextY] == '#') continue;
                if(grid[nextX][nextY] == '*') res++;
                x = nextX, y = nextY;
                grid[nextX][nextY] = '.';
            }
        }
        printf("%d\n",res);
    }
}
