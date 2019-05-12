#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,m,a,b;
    cin >> t;
    while(t--){
        cin >> n >> m;
        // need to be in sorted order
        map<int,unordered_multiset<int>> graph;
        for(int i=0;i<m;i++){
            cin >> a >> b;
            // single directed edge to prevent duplicates
            if(a > b) {
                graph[b].insert(a);
            } else if(a < b) {
                graph[a].insert(b);
            }
        }
        int res = 0;
        // foreach vertex v
        for(auto v : graph){
            // foreach neigh1 of vertex v
            for(auto neigh1 : v.second){
                // foreach neigh2 of vertex neigh1
                for(auto neigh2 : graph[neigh1])
                    // if v and neigh2 is connected, add one
                    if(v.second.count(neigh2)) res++;
            }
        }
        cout << res << endl;
    }
}
