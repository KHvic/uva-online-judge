#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc,n,m,v;
    string in;
    scanf("%d",&tc);
    while(tc--){
        int idx=1;
        unordered_map<string,int> osIdx;
        // osIdx, value
        vector<pair<int,int>> north,south;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            cin >> in >> in >> v;
            if(!osIdx.count(in)) {
                osIdx[in] = idx++;
            }
            north.push_back({osIdx[in], v});
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            cin >> in >> in >> v;
            // if not exist on north, can ignore
            if(osIdx.count(in)) {
                south.push_back({osIdx[in], v});
            }
        }

        n = north.size(), m = south.size();
        // dp
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        vector<vector<int>> num_bridges(n+1, vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int best, best_bridge;
                if(dp[i+1][j] > dp[i][j+1]) {
                    best = dp[i+1][j];
                    best_bridge = num_bridges[i+1][j];
                } else if(dp[i][j+1] > dp[i+1][j]) {
                    best = dp[i][j+1];
                    best_bridge = num_bridges[i][j+1];
                } else {
                    best = dp[i][j+1];
                    best_bridge = min(num_bridges[i][j+1], num_bridges[i+1][j]);
                }

                if(north[i].first == south[j].first) {
                    int connect_val = dp[i][j] + north[i].second + south[j].second;
                    if(connect_val > best) {
                        best = connect_val;
                        best_bridge = num_bridges[i][j] + 1;
                    }
                }
                dp[i+1][j+1] = best;
                num_bridges[i+1][j+1] = best_bridge;
            }
        }
        printf("%d %d\n",dp[n][m], num_bridges[n][m]);
    }
}
