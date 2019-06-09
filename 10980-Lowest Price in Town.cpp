#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,m,n,k,tc=1;
    string in;
    while(scanf("%d.%d %d",&a,&b,&m) != EOF){
        vector<pair<int,int>> sales;
        sales.push_back({1,a*100+b});
        for(int i=0;i<m;i++){
            scanf("%d %d.%d",&n,&a,&b);
            sales.push_back({n,a*100+b});
        }
        cin.ignore();
        getline(cin,in);
        istringstream iss(in);
        vector<int> queries;
        int highest = 0;
        while(iss >> k){
            highest = max(highest,k);
            queries.push_back(k);
        }
        vector<int> dp(highest+1,1e7);
        dp[0] = 0;
        for(auto& offer : sales){
            for(int i=0;i<=highest;i++){
                int newCost = offer.first <= i ? dp[i-offer.first] : 0;
                newCost += offer.second;
                // we can either use this offer or not
                dp[i] = min(dp[i],newCost);
            }
        }
        printf("Case %d:\n",tc++);
        for(auto& query : queries)
            printf("Buy %d for $%.2f\n",query,dp[query]/100.0);
    }
}
