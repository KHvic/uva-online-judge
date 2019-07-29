#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
vector<vector<bool>> visited;
vector<string> grid;

bool dfs(int idx,string& pat,int x,int y){
    if(idx==pat.length()) return true;
    if(x<0||y<0||x>=4||y>=4) return false;
    if(grid[x][y]!=pat[idx] || visited[x][y]) return false;
    visited[x][y] = true;
    for(auto& dir : dirs){
        int nextX = x+dir[0];
        int nextY = y+dir[1];
        if(dfs(idx+1,pat,nextX,nextY)) return true;
    }
    visited[x][y] = false;
    return false;
}

int main()
{
    int t,q,tc=1;
    string in;
    scanf("%d",&t);
    while(t--){
        grid.clear();
        for(int i=0;i<4;i++){
            cin >> in;
            grid.push_back(in);
        }
        cin >> q;
        int score=0;
        for(int i=0;i<q;i++){
            cin >> in;
            bool found = false;
            for(int j=0;j<4&&!found;j++)
                for(int k=0;k<4&&!found;k++){
                    visited.assign(4,vector<bool>(4,false));
                    if(dfs(0,in,j,k)) found = true;
                }
            if(found) {
                if(in.length()==3||in.length()==4) score+=1;
                else if(in.length()==5) score+=2;
                else if(in.length()==6) score+=3;
                else if(in.length()==7) score+=5;
                else score+=11;
            }
        }
        printf("Score for Boggle game #%d: %d\n",tc++,score);
    }
}



