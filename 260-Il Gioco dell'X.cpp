#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dirs = {{-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1}};
vector<string> grid;
int n;

bool dfs(int x,int y,char c){
    if(x<0||x>=n||y<0||y>=n) return false;
    if(grid[x][y] != c) return false;
    if(c=='w' && y==n-1) return true;
    if(c=='b' && x==n-1) return true;
    grid[x][y] = '-';
    for(auto& dir : dirs){
        int nextX = x+dir[0];
        int nextY = y+dir[1];
        if(dfs(nextX,nextY,c)) return true;
    }
    return false;
}

int main() {
    string in; int tc=1;
    while(scanf("%d",&n),n!=0){
        grid.clear();
        for(int i=0;i<n;i++){
            cin >> in;
            grid.push_back(in);
        }
        bool blackWon = false;
        for(int i=0;i<n && !blackWon;i++)
            blackWon = dfs(0,i,'b');
        printf("%d %c\n",tc++,(blackWon?'B':'W'));
    }
}
