#include <bits/stdc++.h>
using namespace std;

string path = "IEHOVA#";
vector<vector<int>> mov = {{0,-1},{-1,0},{0,1}};

void print(vector<int>& dirs){
    for(auto& dir : dirs){
        if(dir == 0) cout << "left";
        else if(dir == 1) cout << "forth";
        else cout << "right";

        if(&dir != &dirs.back()) cout << " ";
        else cout << endl;
    }
}

bool dfs(int r,int c,vector<string>& grid,int idx,vector<int>& dirs){
    if(idx == path.length()){
        print(dirs);
        return true;
    }
    for(int i=0;i<3;i++){
        int x = r+mov[i][0];
        int y = c+mov[i][1];
        if(x<0 || y<0 || y>=grid[0].length()) continue;
        if(grid[x][y] == path[idx]){
            dirs.push_back(i);
            if(dfs(x,y,grid,idx+1,dirs)) return true;
            dirs.pop_back();
        }
    }
    return false;
}

int main()
{
    int t;
    int m,n;
    string in;
    cin >> t;
    while(scanf("%d %d",&m,&n) != EOF){
        vector<string> grid;
        vector<int> dirs;
        for(int i=0;i<m;i++){
            cin >> in;
            grid.push_back(in);
        }
        int c;
        for(int i=0;i<n;i++)
            if(grid.back()[i] == '@') c = i;
        dfs(m-1,c,grid,0,dirs);
    }
}
