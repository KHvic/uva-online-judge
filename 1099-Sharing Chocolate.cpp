#include <bits/stdc++.h>
using namespace std;

vector<int> pieces;
bool dp[(1<<15)+1][101];
bool visited[(1<<15)+1][101];
int bit_sum[(1<<15)+1];

void precomputeSum() {
    for(int i=0;i<(1<<pieces.size());i++){
        int sum = 0;
        for(int j=0;j<pieces.size();j++)
            if(i&(1<<j)) sum += pieces[j];
        bit_sum[i] = sum;
    }
}

// dp trick to drop a parameter as we can recover h with sum/w
// dp state: pieces bitmask not fulfilled, width
bool solve(int bits, int w){
    if(bits == 0 || (bits & bits-1) == 0) return true; // 1 piece left
    if(visited[bits][w]) return dp[bits][w];
    int h = bit_sum[bits]/w;

    visited[bits][w] = true, dp[bits][w] = false;
    bool &res = dp[bits][w];

    int b1 = (bits-1)&bits;
    // split into two bitmask
    while(b1!=0 && !res) {
        int b2 = bits^b1;
        if(b2 > b1) break;

        // split by h, maintain w, divisible by w
        if(bit_sum[b1]%w==0 && bit_sum[b2]%w==0)
            res = solve(b1, w) && solve(b2, w);
        if(res) break;

        // split by w, divisible by h
        if(bit_sum[b1]%h==0 && bit_sum[b2]%h==0){
            int new_w1 = bit_sum[b1]/h;
            int new_w2 = bit_sum[b2]/h;
            res = solve(b1, new_w1) && solve(b2, new_w2);
        }
        b1 = (b1-1)&bits;
    }
    return res;
}

int main() {
    int tc=1;
    int n,w,h,v;
    while(scanf("%d",&n),n){
        scanf("%d %d",&w,&h);
        pieces.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            pieces.push_back(v);
        }
        precomputeSum();
        memset(visited, 0, sizeof visited);
        memset(dp, 0, sizeof dp);
        int init_bits = (1<<n)-1;

        printf("Case %d: ", tc++);
        if(bit_sum[init_bits] == (w*h) && solve(init_bits,w))
            printf("Yes\n");
        else printf("No\n");
    }
}
