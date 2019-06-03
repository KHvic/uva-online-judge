#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dimsums;
int n,x,t,k,p,v,limit;

int knapsack(int idx,int remainingDimsum,int spent,vector<vector<vector<int>>>& memo){
    if(remainingDimsum < 0 || spent > limit) return INT_MIN;
    if(idx == dimsums.size() || remainingDimsum == 0) return 0;
    if(memo[idx][remainingDimsum][spent] != -1) return memo[idx][remainingDimsum][spent];
    int res = knapsack(idx+1,remainingDimsum,spent,memo);
    res = max(res,knapsack(idx+1,remainingDimsum-1,spent+dimsums[idx].first,memo)+dimsums[idx].second);
    res = max(res,knapsack(idx+1,remainingDimsum-2,spent+dimsums[idx].first*2,memo)+2*dimsums[idx].second);
    return memo[idx][remainingDimsum][spent] = res;
}

int main()
{
    while(scanf("%d %d %d %d",&n,&x,&t,&k),n||x||t||k){
        vector<vector<vector<int>>> memo(k,vector<vector<int>>(2*(n+1)+1,vector<int>((n+1)*x+1,-1)));
        dimsums.clear();
        for(int i=0;i<k;i++){
            limit = floor(x * (n + 1) / 1.1 + 1e-9);
            cin >> p;
            int sum = 0;
            for(int i=0;i<=n;i++){
                cin >> v;
                sum += v;
            }
            dimsums.push_back({p,sum});
        }
        int totalFavor = knapsack(0,2*(n+1),(n+1)*t,memo);
        printf("%.2f\n",(double)totalFavor/(n+1));
    }
}
