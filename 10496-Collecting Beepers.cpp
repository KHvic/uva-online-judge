#include <bits/stdc++.h>
using namespace std;

// time complexity: O(2^n * n^2)
// there are n cities with 2^n bitmask visited states.
// each state has a forloop that takes O(n)
int t,n,xsize,ysize,x[11],y[11];
int manhattan[11][11],memo[11][1<<11];

// bitmask track the i-th city is visited or not
int tsp(int pos,int bitmask){
    if(bitmask == ((1<<(n+1))-1))
        return manhattan[pos][0]; // last to first city
    if(memo[pos][bitmask] != -1)
        return memo[pos][bitmask];

    int res = 1e8;
    for(int nxt = 1; nxt <= n; nxt++)
        if(nxt != pos && !(bitmask & (1<<nxt)))
            res = min(res,tsp(nxt,bitmask|(1<<nxt)) + manhattan[pos][nxt]);
    return memo[pos][bitmask] = res;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&xsize,&ysize);
        scanf("%d %d",x,y);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",x+i,y+i);
        // compute manhattan distance between cities
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                manhattan[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
        memset(memo,-1,sizeof memo);
        printf("The shortest path has length %d\n", tsp(0,1));
    }
}
