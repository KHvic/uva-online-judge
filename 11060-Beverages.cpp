#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,tc=1;
    string a,b;
    while(scanf("%d",&n)!=EOF){
        unordered_map<string,int> idx;
        vector<string> drinks;
        unordered_map<int,unordered_set<int>> graph;
        for(int i=0;i<n;i++){
            cin >> a;
            drinks.push_back(a);
            idx[a]=i;
        }
        vector<int> indegree(drinks.size());
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            cin >> a >> b;
            int idxA = idx[a];
            int idxB = idx[b];
            if(!graph[idxA].count(idxB)){
                graph[idxA].insert(idxB);
                indegree[idxB]++;
            }
        }
        // priority queue of index to output in given order
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<indegree.size();i++)
            if(!indegree[i])
                q.push(i);
        printf("Case #%d: Dilbert should drink beverages in this order:", tc++);
        while(!q.empty()){
            int cur = q.top(); q.pop();
            cout << " " << drinks[cur];
            for(auto& neighbor : graph[cur]){
                if(--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        printf(".\n\n");
    }
}
