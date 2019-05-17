#include <bits/stdc++.h>

using namespace std;
int res;
void backtrack(int sum,vector<int>& board,vector<bool>& rows,
    vector<bool>& diag1,vector<bool>& diag2,int c){
    if(c == 8) {
        res = min(sum,res);
        return;
    }
    for(int i=0;i<8;i++){
        if(rows[i] || diag1[i-c+7] || diag2[c+i]) continue;
        rows[i] = diag1[i-c+7] = diag2[c+i] = true;
        backtrack(sum+(i==board[c] ? 0 : 1),board,rows,diag1,diag2,c+1);
        rows[i] = diag1[i-c+7] = diag2[c+i] = false;
    }
}

int main()
{
    int v;
    int tc=1;
    while(cin>>v){
        res = INT_MAX;
        vector<bool> rows(8);
        vector<bool> diag1(8);
        vector<bool> diag2(16);
        vector<int> board(1,v-1);
        for(int j=1;j<8;j++){
            cin >> v;
            board.push_back(v-1);
        }
        backtrack(0,board,rows,diag1,diag2,0);
        printf("Case %d: %d\n",tc++,res);
    }
}
