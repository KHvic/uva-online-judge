#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> treasures;
vector<vector<bool>> chosen; // for reconstruction
vector<vector<int>> dp; // store best value for index i with time t

int knapsack(int idx,int t){
    if(t<0) return INT_MIN;
    if(idx == treasures.size() || t == 0) return 0;
    if(dp[idx][t] != -1) return dp[idx][t];
    int without = knapsack(idx+1,t);
    dp[idx][t] = without;
    if(treasures[idx].first <= t){
        int with = knapsack(idx+1,t-treasures[idx].first) + treasures[idx].second;
        if(with > without) {
            // for item idx with t time left, choosing this treasure is better
            // mark it for reconstruction
            chosen[idx][t] = true;
            dp[idx][t] = with;
        }
    }
    return dp[idx][t];
}

int main()
{
    int t,w,n,d,v,tc=1;
    while(scanf("%d %d",&t,&w) != EOF){
        if(tc++>1) printf("\n");
        scanf("%d",&n);
        treasures.clear();
        chosen = vector<vector<bool>>(n+1,vector<bool>(t+1));
        dp = vector<vector<int>>(n+1,vector<int>(t+1,-1));

        for(int i=0;i<n;i++){
            scanf("%d %d",&d,&v);
            treasures.push_back({d*3*w,v});
        }
        int maxValue = knapsack(0,t);
        printf("%d\n",maxValue);
        vector<int> chosenIndex;

        // reconstruct treasure listing
        for(int i=0;i<n;i++){
            if(chosen[i][t]){
                chosenIndex.push_back(i);
                t -= treasures[i].first;
            }
        }
        printf("%d\n",chosenIndex.size());
        for(auto& idx : chosenIndex)
            printf("%d %d\n",treasures[idx].first/(3*w),treasures[idx].second);
    }
}
