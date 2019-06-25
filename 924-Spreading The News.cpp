#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,q,v;
    string in;
    scanf("%d",&n);
    vector<unordered_set<int>> graph(n);
    vector<bool> visited;
    for(int i=0;i<n;i++){
        cin >> q;
        for(int j=0;j<q;j++){
            cin >> v;
            graph[i].insert(v);
        }
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> v;
        visited.assign(n,false);
        int day1 = 0;
        int maxBloom = 0;
        queue<int> bfs;
        bfs.push(v);
        visited[v] = true;
        int steps = 0;
        while(!bfs.empty()){
            int len = bfs.size();
            int bloom = 0;
            for(int j=0;j<len;j++){
                int cur = bfs.front(); bfs.pop();
                for(int neigh : graph[cur]){
                    if(!visited[neigh]){
                        bloom++;
                        visited[neigh] = true;
                        bfs.push(neigh);
                    }
                }
            }
            steps++;
            if(bloom > maxBloom){
                maxBloom = bloom;
                day1 = steps;
            }
        }
        if(day1 == 0) printf("%d\n",day1);
        else {
            printf("%d %d\n",maxBloom,day1);
        }
    }
}
