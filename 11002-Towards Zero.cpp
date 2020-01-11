#include <bits/stdc++.h>
using namespace std;

int n, v;
vector<vector<int>> board;
int memo[61][31][3001];

int solve(int idx, int col, int val){
    if(idx == 0) {
        return abs(val);
    }
    int &dp = memo[idx][col][val];
    if(dp != -1) return dp;
    dp = INT_MAX;
    bool top_half = idx < n;
    if(top_half){
        if(col>0){
            int add_left = abs(val + board[idx-1][col-1]);
            int sub_left = abs(val - board[idx-1][col-1]);
            dp = min(dp, solve(idx-1,col-1,add_left));
            dp = min(dp, solve(idx-1,col-1,sub_left));
        }
        if(col<idx){
            int add_right = abs(val + board[idx-1][col]);
            int sub_right = abs(val - board[idx-1][col]);
            dp = min(dp, solve(idx-1,col,add_right));
            dp = min(dp, solve(idx-1,col,sub_right));
        }
    }else{
        int add_left = abs(val + board[idx-1][col]);
        int sub_left = abs(val - board[idx-1][col]);
        int add_right = abs(val + board[idx-1][col+1]);
        int sub_right = abs(val - board[idx-1][col+1]);
        dp = min(dp, solve(idx-1,col,add_left));
        if(idx != 2*n-1) dp = min(dp, solve(idx-1,col,sub_left));
        dp = min(dp, solve(idx-1,col+1,add_right));
        if(idx != 2*n-1) dp = min(dp, solve(idx-1,col+1,sub_right));
    }
    return dp;
}

int main() {
    while(scanf("%d",&n),n){
        board.clear();
        for(int i=0;i<2*n-1;i++){
            vector<int> row;
            for(int j=0;j<n-abs(n-i-1);j++){
                scanf("%d",&v);
                row.push_back(v);
            }
            board.push_back(row);
        }
        memset(memo, -1, sizeof memo);
        printf("%d\n",solve(board.size()-1,0,board.back()[0]));
    }
}
