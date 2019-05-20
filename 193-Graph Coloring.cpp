#include <bits/stdc++.h>
using namespace std;

int black;
vector<int> res;

void dfs(int idx,unordered_map<int,unordered_set<int>>& graph,vector<int>& colors){
    if(idx == colors.size()){
        if(black > res.size()){
            res.clear();
            for(int i=0;i<colors.size();i++)
                if(colors[i] == 1) res.push_back(i+1);
        }
        return;
    }
    // try black
    bool canBlack = true;
    for(auto& neigh : graph[idx]){
        if(colors[neigh] == 1){
            canBlack = false;
            break;
        }
    }
    if(canBlack){
        black++;
        colors[idx] = 1;
        dfs(idx+1,graph,colors);
        black--;
    }
    // white
    colors[idx] = -1;
    dfs(idx+1,graph,colors);
}

int main()
{
    int t,n,k,a,b;
    cin >> t;
    while(t--){
        unordered_map<int,unordered_set<int>> graph;
        cin >> n >> k;
        vector<int> colors(n);
        res.clear(); black = 0;
        for(int i=0;i<k;i++){
            cin >> a >> b;
            graph[a-1].insert(b-1);
            graph[b-1].insert(a-1);
        }
        dfs(0,graph,colors);
        printf("%d\n",res.size());
        for(auto& black : res){
            cout << black;
            if(&black == &res.back()) cout << endl;
            else cout << " ";
        }
    }
}
