#include <bits/stdc++.h>
using namespace std;

vector<int> memo(1<<12,1e7);

int solve(int bitmask){
    if(memo[bitmask] != 1e7) return memo[bitmask];
    int cnt=0;
    int best = 1e7;
    for(int i=0;i<12;i++){
        if(bitmask &(1<<i)) cnt++;
        else continue;
        // check right jump
        if(i>=2) {
            if(bitmask &(1<<(i-1)) && !(bitmask&(1<<(i-2)))){
                int next_bitmask = bitmask ^ (0x7 << (i-2));
                best = min(best, solve(next_bitmask));
            }
        }
        // check left jump
        if(i<=9) {
            if(bitmask &(1<<(i+1)) && !(bitmask&(1<<(i+2)))){
                int next_bitmask = bitmask ^ (0x7 << i);
                best = min(best, solve(next_bitmask));
            }
        }
    }
    return memo[bitmask] = min(best,cnt);
}

int main() {
    for(int i=0;i<12;i++)
        memo[1<<i] = 1;
    int tc;
    string in;
    scanf("%d",&tc);
    while(tc--){
        cin >> in;
        int bitmask = 0;
        for(int i=0;i<12;i++)
            if(in[i]=='o')
                bitmask |= (1<<i);
        printf("%d\n",solve(bitmask));
    }
}
