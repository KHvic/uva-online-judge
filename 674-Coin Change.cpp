#include <bits/stdc++.h>
using namespace std;
int n,v;
vector<int> coins = {1,5,10,25,50};
int memo[6][7500];

int ccWays(int idx,int remain){
    if(remain == 0) return 1;
    if(remain < 0 || idx == 5) return 0;
    if(memo[idx][remain] != -1) return memo[idx][remain];
    return memo[idx][remain] = ccWays(idx+1,remain) + ccWays(idx,remain-coins[idx]);
}

int main()
{
    memset(memo,-1,sizeof(memo));
    while(scanf("%d",&v) != EOF)
        printf("%d\n",ccWays(0,v));
}
