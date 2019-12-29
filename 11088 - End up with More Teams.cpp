#include <bits/stdc++.h>
using namespace std;

vector<int> memo;
vector<int> ppl;

int solve(int bitmask){
    if(memo[bitmask]!=-1) return memo[bitmask];

    int best = 0;
    for(int i=0;i<ppl.size();i++){
        if(bitmask & (1<<i)) continue;
        for(int j=i+1;j<ppl.size();j++){
            if(bitmask & (1<<j)) continue;
            for(int k=j+1;k<ppl.size();k++){
                if(bitmask & (1<<k)) continue;
                int sum = ppl[i]+ppl[j]+ppl[k];
                if(sum < 20) continue;
                int next_bitmask = bitmask | (1<<i) | (1<<j) | (1<<k);
                best = max(best, 1+solve(next_bitmask));
            }
        }
    }
    return memo[bitmask] = best;
}

int main() {
    int tc=1,n,v;
    while(scanf("%d",&n),n){
        memo.assign(1<<n,-1);
        ppl.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            ppl.push_back(v);
        }
        printf("Case %d: %d\n",tc++, solve(0));
    }
}
