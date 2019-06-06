#include <bits/stdc++.h>
using namespace std;

int l, n, cut[55], memo[55][55];

int minCost(int left, int right){
    if(left+1 == right) return 0;
    if(memo[left][right] != -1) return memo[left][right];
    int res = 1e8;
    // try each cutting spot
    for(int i=left+1;i<right;i++)
        res = min(res, minCost(left,i)+minCost(i,right)+(cut[right]-cut[left]));
    return memo[left][right] = res;
}

int main()
{
    while(scanf("%d",&l),l){
        cut[0] = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",cut+i);
        cut[n+1] = l;
        memset(memo,-1,sizeof memo);
        printf("The minimum cutting is %d.\n", minCost(0,n+1));
    }
}
