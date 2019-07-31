#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<bool> visited;
vector<vector<pair<int,int>>> mst;
int highest = 0;

int find(int x){
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void join(int a,int b){
    int parA = find(a), parB = find(b);
    parent[parA] = parB;
}

bool connected(int a,int b){
    return find(a) == find(b);
}

bool dfs(int cur,int target){
    if(cur == target) return true;
    if(visited[cur]) return false;
    visited[cur] = true;
    for(auto& edge : mst[cur]){
        if(dfs(edge.first,target)) {
            highest = max(highest, edge.second);
            return true;
        }
    }
    return false;
}

int main()
{
    int c,s,q,a,b,w,tc=1;
    bool first = true;
    while(scanf("%d %d %d",&c,&s,&q),(c+s+q)!=0){
        if(!first) printf("\n");
        first = false;
        parent.assign(c,0);
        mst.assign(c,vector<pair<int,int>>());
        for(int i=0;i<c;i++) parent[i] = i;
        vector<tuple<int,int,int>> edges;
        for(int i=0;i<s;i++){
            scanf("%d %d %d",&a,&b,&w);
            a--; b--;
            edges.push_back(make_tuple(w,a,b));
        }
        sort(edges.begin(),edges.end());
        for(auto& edge : edges){
            tie(w,a,b) = edge;
            if(!connected(a,b)){
                join(a,b);
                mst[a].push_back({b,w});
                mst[b].push_back({a,w});
            }
        }
        printf("Case #%d\n",tc++);
        for(int i=0;i<q;i++){
            scanf("%d %d",&a,&b);
            a--; b--;
            if(connected(a,b)){
                visited.assign(c,false);
                highest = INT_MIN;
                dfs(a,b);
                printf("%d\n",highest);
            } else {
                printf("no path\n");
            }
        }
    }
}
