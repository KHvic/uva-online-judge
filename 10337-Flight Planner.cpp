#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,dist,v;
    cin >> t;
    while(t--){
        cin >> dist;
        dist/=100;
        deque<vector<int>> wind;
        for(int i=0;i<10;i++){
            vector<int> row;
            for(int j=0;j<dist;j++){
                cin >> v;
                row.push_back(v);
            }
            wind.push_front(row);
        }
        vector<int> dp(10,1e7);
        dp[0] = 0;
        for(int i=0;i<dist;i++){
            vector<int> dpNext(10,0);
            for(int j=0;j<10;j++){
                int fromBelow = j==0 ? 1e7 : (dp[j-1] + 60 - wind[j-1][i]);
                int fromAbove = j==9 ? 1e7 : (dp[j+1] + 20 - wind[j+1][i]);
                int stay = dp[j] + 30 - wind[j][i];
                dpNext[j] = min(stay, min(fromBelow, fromAbove));
            }
            dp = dpNext;
        }
        printf("%d\n\n",dp[0]);
    }
}
