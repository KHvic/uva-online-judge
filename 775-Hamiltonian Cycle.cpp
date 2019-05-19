#include <bits/stdc++.h>
using namespace std;
bitset<270> used;
int n;

bool dfs(vector<int>& cur,unordered_map<int,set<int>>& graph){
    if(cur.size() == n+1){
        if(cur.back() == 1) return true;
        return false;
    }
    int prev = cur.back();
    for(auto& next : graph[prev]){
        if(used[next]||(next==1 && cur.size() != n)) continue;
        used[next] = 1;
        cur.push_back(next);
        if(dfs(cur,graph)) return true;
        cur.pop_back();
        used[next] = 0;
    }
    return false;
}

int main()
{
    string in;
    while(scanf("%d\n",&n) != EOF){
        used.reset();
        unordered_map<int,set<int>> graph;
        while(getline(cin,in),in != "%"){
            int delim = in.find(" ");
            int a = stoi(in.substr(0,delim));
            int b = stoi(in.substr(delim+1));
            graph[a].insert(b);
            graph[b].insert(a);
        }
        vector<int> cur(1,1);
        if(dfs(cur,graph)){
            for(auto& v : cur){
                cout << v;
                if(&v == &cur.back()) cout << endl;
                else cout << " ";
            }
        } else {
            cout << "N" << endl;
        }
    }
}
