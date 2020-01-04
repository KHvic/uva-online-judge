#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> turtles;
    int w,s;
    while(scanf("%d %d",&w,&s) == 2) {
        turtles.push_back({s,w});
    }
    // (greedy) sort by min strength, because they can carry less
    sort(turtles.begin(), turtles.end());
    vector<int> dp(turtles.size(),1e7); // dp of minimum weight for stack size i
    dp[0] = 0;
    int res = 0;
    for(int i=0;i<turtles.size();i++){
        for(int j=res;j>=0;j--){
            if(turtles[i].first - turtles[i].second - dp[j] < 0) continue;
            dp[j+1] = min(dp[j+1], dp[j]+turtles[i].second); // minimize stack weight
            res = max(res, j+1);
        }
    }
    printf("%d\n", res);
}
