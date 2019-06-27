#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,m,x,y,v;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<tuple<int,int,int>> graph;
        vector<int> dist(n,1e7);
        for(int i=0;i<m;i++){
            cin >> x >> y >> v;
            graph.push_back(make_tuple(x,y,v));
        }
        dist[0] = 0;
        bool hasNeg = false;
        for(int i=0;i<n;i++){
            for(auto& edge : graph){
                tie(x,y,v) = edge;
                int nextCost = dist[x] + v;
                if(nextCost < dist[y]){
                    if(i == n-1) hasNeg = true;
                    dist[y] = nextCost;
                }
            }
        }
        cout << (hasNeg ? "possible" : "not possible") << endl;
    }
}
