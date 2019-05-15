#include <bits/stdc++.h>

using namespace std;

void dfs(int r, int c,vector<bool> &rowTaken,vector<bool> &colTaken,char grid[4][4],int &best, int cur){
    if(r==rowTaken.size()){
        best = max(cur,best);
        return;
    } else if(c==colTaken.size()){
        dfs(r+1,0,rowTaken,colTaken,grid,best,cur);
        return;
    }
    // try placing
    if(grid[r][c] != 'X' && !rowTaken[r] && !colTaken[c]){
        rowTaken[r] = colTaken[c] = true;
        dfs(r,c+1,rowTaken,colTaken,grid,best,cur+1);
        rowTaken[r] = colTaken[c] = false;
    }
    // without placing
    if(grid[r][c] == 'X'){
        // obstacle will allow rook in same col&row
        bool rowIsTaken = rowTaken[r];
        bool colIsTaken = colTaken[c];
        rowTaken[r] = colTaken[c] = false;
        dfs(r,c+1,rowTaken,colTaken,grid,best,cur);
        rowTaken[r] = rowIsTaken;
        colTaken[c] = colIsTaken;
    } else {
        dfs(r,c+1,rowTaken,colTaken,grid,best,cur);
    }
}

int main()
{
    int n;
    char grid[4][4];
    while(scanf("%d",&n),n){
        vector<bool> rowTaken(n);
        vector<bool> colTaken(n);
        for(int i=0;i<n;i++){
            scanf("%s",grid[i]);
        }
        int best = 0;
        dfs(0,0,rowTaken,colTaken,grid,best,0);
        cout << best << endl;
    }
}
