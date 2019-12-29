#include <bits/stdc++.h>
using namespace std;

int ok = (1<<16)-1;
vector<int> memo(1<<16,-1);

vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

bool solve(int bitmask) {
    if(bitmask == ok) return true;
    if(memo[bitmask] != -1) return memo[bitmask] == 1;

    bool solved = false;
    for(int i=0;i<4 && !solved;i++){
        for(int j=0;j<4 && !solved;j++){
            int idx = i*4+j;
            if(bitmask & (1<<idx)) continue;
            int next_bitmask = bitmask | (1<<idx);
            solved = !solve(next_bitmask);
            if(solved) break;

            for(auto& dir : dirs){
                bool ok = true;
                int x=i,y=j;
                int next_bitmask = bitmask;
                while(ok && x>=0 && y>=0 && x<4 && y<4){
                    idx = x*4+y;
                    // check if already covered and pin is not larger than size 3
                    if(bitmask & (1<<idx) || abs(x-i)>2 || abs(y-j)>2) {
                        ok=false; break;
                    }
                    next_bitmask |= (1<<idx);
                    x += dir[0], y+= dir[1];
                }
                if(ok) {
                    solved = !solve(next_bitmask);
                    if(solved) break;
                }
            }
        }
    }
    return memo[bitmask] = solved ? 1 : 0;
}

int main() {
    int t;
    string in;
    scanf("%d",&t);
    while(t--){
        int bits = 0;
        for(int i=0;i<4;i++){
            cin >> in;
            for(int j=0;j<4;j++)
                if(in[j] == 'X') bits |= 1<<(i*4+j);
        }
        if(solve(bits)) printf("WINNING\n");
        else printf("LOSING\n");
    }
}
