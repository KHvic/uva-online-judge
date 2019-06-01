#include <bits/stdc++.h>
using namespace std;

int t,n,v,q;
int memo[1010][40];
int value[1010];
int weight[1010];

int bestValue(int idx, int weightLeft){
    if (idx == n || weightLeft == 0) return 0;
    if(memo[idx][weightLeft] != -1) return memo[idx][weightLeft];
    // cannot fit this item
    if(weight[idx] > weightLeft)
        return memo[idx][weightLeft] = bestValue(idx+1,weightLeft);
    return memo[idx][weightLeft] = max(
        bestValue(idx+1,weightLeft),
        value[idx]+bestValue(idx+1,weightLeft-weight[idx]));
}

int main()
{
    scanf("%d",&t);
    while(t--){
        memset(memo,-1,sizeof(memo));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",value+i,weight+i);
        int ans = 0;
        scanf("%d",&q);
        while(q--){
            scanf("%d",&v);
            ans += bestValue(0,v);
        }
        printf("%d\n",ans);
    }
}
