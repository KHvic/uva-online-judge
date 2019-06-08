#include <bits/stdc++.h>
using namespace std;
int memo[27][352][27];

int solve(int remLen, int val, int pos){
    if(remLen == 0 && val == 0) return 1;
    else if(remLen <= 0 || val <= 0 || pos> 26) return 0;
    if(memo[remLen][val][pos] != -1) return memo[remLen][val][pos];

    int res = 0;
    for(int i=pos;i<=26;i++)
        res += solve(remLen-1,val-i,i+1);
    return memo[remLen][val][pos] = res;
}

int main()
{
    memset(memo,-1,sizeof memo);
    int tc=1,l,s;
    while(scanf("%d %d",&l,&s),(l+s)!=0){
        printf("Case %d: %d\n",tc++, (l > 26 || s > 352) ? 0 : solve(l,s,1));
    }
}
