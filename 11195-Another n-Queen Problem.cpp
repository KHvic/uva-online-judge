#include <bits/stdc++.h>
using namespace std;

int ok, n;
int ans;
vector<int> colBits; // additional constraint to check whether is a bad square

void backtrack(int rw, int ld, int rd, int col) {
    if (rw == ok) {
        ans++;
        return;
    }
    // list of valid row position for this column
    int pos = ok & (~(rw | ld | rd));
    while (pos) {
        int p = pos & -pos;
        pos -= p;
        if(colBits[col] & p) continue; // bad square constraint
        backtrack(rw | p, (ld | p) << 1, (rd | p) >> 1, col+1);
    }
}

int main() {
    int tc=1;
    while(scanf("%d",&n),n){
        char c;
        ok = (1 << n)-1;
        ans = 0;
        colBits.assign(n, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> c;
                if(c == '*') colBits[j] = (colBits[j] << 1) + 1;
                else colBits[j] = (colBits[j] << 1);
            }
        }
        backtrack(0, 0, 0, 0);
        printf("Case %d: %d\n", tc++, ans);
    }
}
