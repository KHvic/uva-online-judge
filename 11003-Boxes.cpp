#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> boxes;
vector<vector<int>> dp;
int n,wt,load;

int knapsack(int idx, int remainingWeight){
    if(idx == n || remainingWeight == 0) return 0;
    if(dp[idx][remainingWeight] != -1) return dp[idx][remainingWeight];
    dp[idx][remainingWeight] = knapsack(idx+1,remainingWeight);
    if(remainingWeight >= boxes[idx].first){
        int limit = min(remainingWeight-boxes[idx].first,boxes[idx].second);
        dp[idx][remainingWeight] = max(dp[idx][remainingWeight],
                                       knapsack(idx+1,limit)+1);
    }
    return dp[idx][remainingWeight];
}

int main()
{
    while(cin >> n,n){
        boxes.clear();
        int maxWeight = 0;
        for(int i=0;i<n;i++){
            cin >> wt >> load;
            boxes.push_back({wt,load});
            maxWeight = max(maxWeight,max(wt,load));
        }
        dp = vector<vector<int>>(n,vector<int>(maxWeight+1,-1));
        printf("%d\n",knapsack(0,maxWeight));
    }
}
