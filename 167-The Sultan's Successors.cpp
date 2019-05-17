#include <bits/stdc++.h>

using namespace std;
int res;
void backtrack(int sum,vector<vector<int>>& grid,vector<bool>& rows,
    vector<bool>& diag1,vector<bool>& diag2,int c){
    if(c == 8) {
        res = max(sum,res);
        return;
    }
    for(int i=0;i<8;i++){
        if(rows[i] || diag1[i-c+7] || diag2[c+i]) continue;
        rows[i] = diag1[i-c+7] = diag2[c+i] = true;
        backtrack(sum+grid[i][c],grid,rows,diag1,diag2,c+1);
        rows[i] = diag1[i-c+7] = diag2[c+i] = false;
    }
}

int main()
{
    int t,v;
    cin >> t;
    while(t--){
        res = INT_MIN;
        vector<bool> rows(8);
        vector<bool> diag1(8);
        vector<bool> diag2(16);
        vector<vector<int>> grid(8,vector<int>(8));
        for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
            cin >> v;
            grid[i][j] = v;
        }
        backtrack(0,grid,rows,diag1,diag2,0);
        cout << setfill(' ') << setw(5) << res << endl;
    }
}
