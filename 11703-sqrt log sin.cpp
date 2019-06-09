#include <bits/stdc++.h>
using namespace std;

int memo[1000001] = {};
int solve(int n){
    if(memo[n] != -1) return memo[n];
    int res = solve(floor(n-sqrt(n)));
    res += solve(floor(log(n)));
    res += solve(floor(n*sin(n)*sin(n)));
    return memo[n] = res%1000000;
}

int main()
{
    memset(memo,-1,sizeof memo);
    memo[0] = 1;
    int n;
    while(scanf("%d",&n),n!=-1)
        printf("%d\n",solve(n));
}
