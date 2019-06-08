#include <bits/stdc++.h>
using namespace std;

int n,k,m;
long long memo[51][51];
long long solve(int remLength, int remK){
    if(remLength == 0 && remK == 0) return 1;
    else if(remK == 0 || remLength <=0) return 0;
    if(memo[remLength][remK] != -1) return memo[remLength][remK];
    long long res = 0;
    for(int i=1;i<=m;i++)
        res += solve(remLength-i, remK-1);
    return memo[remLength][remK] = res;
}

int main() {
    while(scanf("%d %d %d",&n,&k,&m) != EOF){
        memset(memo,-1,sizeof memo);
        printf("%lld\n", solve(n,k));
    }
}
