#include <bits/stdc++.h>
using namespace std;

int n,c,o,v;
vector<int> items;
vector<vector<int>> combos;
vector<int> memo;

int solve(int bitmask){
    if(memo[bitmask] != 1e7) return memo[bitmask];
    vector<int> needs(n);
    int best = 0;
    int bits = bitmask;
    for(int i=n-1;i>=0;i--) {
        needs[i] = bits & 0xf;
        bits >>= 4;
        best += needs[i]*items[i];
    }
    for(int i=0;i<combos.size();i++){
        int nextBits = 0;
        bool over = false;
        for(int j=0;j<n && !over;j++){
            int next = needs[j] - combos[i][j];
            if(next<0) {
                over = true;
                break;
            }
            nextBits <<= 4;
            nextBits += next;
        }
        if(!over){
            best = min(best, solve(nextBits) + combos[i][n]);
        }
    }
    return memo[bitmask] = best;
}

int main() {
    while(scanf("%d",&n) != EOF){
        items.clear(), combos.clear();
        memo.assign(1<<(4*n),1e7);
        memo[0] = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            items.push_back(v);
        }
        scanf("%d",&c);
        for(int i=0;i<c;i++){
            vector<int> combo;
            for(int j=0;j<=n;j++){
                scanf("%d",&v);
                combo.push_back(v);
            }
            combos.push_back(combo);
        }
        scanf("%d",&o);
        for(int i=0;i<o;i++){
            int bits = 0;
            for(int j=0;j<n;j++){
                scanf("%d",&v);
                bits <<= 4;
                bits += v;
            }
            printf("%d\n", solve(bits));
        }
    }
}
