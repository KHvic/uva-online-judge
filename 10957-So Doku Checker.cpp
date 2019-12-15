#include <bits/stdc++.h>

using namespace std;

const int n=9,n1=3;
vector<int> row,col,sq;
vector<vector<int>> board;

int solve(int x,int y){
    if(x==n) return 1;
    else if(y==n) return solve(x+1,0);
    if(board[x][y] != 0) return solve(x,y+1);

    int sqIdx = (x/n1)*n1+y/n1;
    int validBit = row[x] & col[y] & sq[sqIdx];
    int solCnt = 0;
    while(validBit != 0){
        int p = validBit & -validBit;
        row[x] ^= p;
        col[y] ^= p;
        sq[sqIdx] ^= p;
        solCnt += solve(x,y+1);
        if(solCnt > 1) return 2;
        row[x] ^= p;
        col[y] ^= p;
        sq[sqIdx] ^= p;
        validBit -= p;
    }
    return solCnt;
}

int main() {
    int tc=1,v;
    while(scanf("%d",&v) != EOF) {
        row.assign(n,(1<<n) - 1);
        col.assign(n,(1<<n) - 1);
        sq.assign(n,(1<<n) - 1);
        board.clear();
        bool alreadyInvalid = false;
        for(int i=0;i<n;i++){
            vector<int> r;
            for(int j=0;j<n;j++){
                if(i+j != 0)scanf("%d",&v);
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
        printf("Case %d: ",tc++);
        if(alreadyInvalid) printf("Illegal.\n");
        else {
            int sol = solve(0,0);
            if(sol == 0) printf("Impossible.\n");
            else if(sol == 1) printf("Unique.\n");
            else printf("Ambiguous.\n");
        }
    }
}

