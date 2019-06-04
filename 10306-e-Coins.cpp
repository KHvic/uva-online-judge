#include <bits/stdc++.h>
using namespace std;

int t,m,s,x,y;
vector<pair<int,int>> coins;
vector<vector<vector<int>>> dp;

int coinChange(int idx,int a,int b){
    int remain = s*s-(a*a+b*b);
    if(remain == 0) return 0;
    else if(remain < 0 || idx == coins.size()) return 1e8;
    if(dp[idx][a][b] != -1) return dp[idx][a][b];
    int without = coinChange(idx+1,a,b);
    int with = coinChange(idx,a+coins[idx].first,b+coins[idx].second);
    if(with != 1e8) with += 1;
    return dp[idx][a][b] = min(without,with);
}

int main()
{
    cin >> t;
    while(t--){
        cin >> m >> s;
        coins.clear();
        dp = vector<vector<vector<int>>>(m+1,vector<vector<int>>(s+1,vector<int>(s+1,-1)));
        for(int i=0;i<m;i++){
            cin >> x >> y;
            coins.push_back({x,y});
        }
        int res = coinChange(0,0,0);
        if(res == 1e8) printf("not possible\n");
        else printf("%d\n",res);
    }
}
