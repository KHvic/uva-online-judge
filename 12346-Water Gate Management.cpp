#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,f,c;
    cin >> n;
    vector<pair<int,int>> gates;
    for(int i=0;i<n;i++){
        cin >> f >> c;
        gates.push_back({f,c});
    }
    int tc = 1, t;
    cin >> t;
    while(t--){
        int best = INT_MAX;
        cin >> f >> c;
        for(int i=0;i<(1<<n);i++){
            int maxFlow = 0;
            int cost = 0;
            for(int j=0;j<n;j++)
            if(i & (1<<j)){
                maxFlow += (c*gates[j].first);
                cost += gates[j].second;
            }
            if(maxFlow > f)
                best = min(best,cost);
        }
        if(best == INT_MAX) printf("Case %d: IMPOSSIBLE\n",tc++);
        else printf("Case %d: %d\n",tc++,best);
    }
}
