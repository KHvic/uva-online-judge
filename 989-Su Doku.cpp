#include <bits/stdc++.h>

using namespace std;

int n,n1;
vector<int> row,col,sq;
vector<vector<int>> board;

bool solve(int x,int y){
    if(x==n) return true;
    else if(y==n) return solve(x+1,0);
    if(board[x][y] != 0) return solve(x,y+1);

    int sqIdx = (x/n1)*n1+y/n1;
    int validBit = row[x] & col[y] & sq[sqIdx];
    for(int i=0;i<9;i++)
    if(validBit & (1<<i)) {
        row[x] ^= (1<<i);
        col[y] ^= (1<<i);
        sq[sqIdx] ^= (1<<i);
        board[x][y] = i+1;
        if(solve(x,y+1)) return true;
        board[x][y] = 0;
        row[x] ^= (1<<i);
        col[y] ^= (1<<i);
        sq[sqIdx] ^= (1<<i);
    }
    return false;
}

int main() {
    int v;
    bool notfirst = false;
    while(scanf("%d",&n1) != EOF) {
        if(notfirst) printf("\n");
        notfirst = true;

        n=n1*n1;
        row.assign(n,(1<<n) - 1);
        col.assign(n,(1<<n) - 1);
        sq.assign(n,(1<<n) - 1);
        board.clear();
        bool alreadyInvalid = false;
        for(int i=0;i<n;i++){
            vector<int> r;
            for(int j=0;j<n;j++){
                scanf("%d",&v);
                r.push_back(v);
                if(v != 0) {
                    v--;
                    int sqIdx = (i/n1)*n1+j/n1;
                    if(((row[i]>>v)&1) == 0) alreadyInvalid = true;
                    if(((col[j]>>v)&1) == 0) alreadyInvalid = true;
                    if(((sq[sqIdx]>>v)&1) == 0) alreadyInvalid = true;
                    row[i] ^= (1<<v);
                    col[j] ^= (1<<v);
                    sq[sqIdx] ^= (1<<v);
                }
            }
            board.push_back(r);
        }
        if(!alreadyInvalid && solve(0,0)) {
            for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                printf("%d",board[i][j]);
                if(j==n-1) printf("\n");
                else printf(" ");
            }
        } else
            printf("NO SOLUTION\n");
    }
}

