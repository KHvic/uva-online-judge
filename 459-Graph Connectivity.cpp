#include <bits/stdc++.h>
using namespace std;
unordered_set<char> visited;
unordered_map<char,unordered_set<char>> graph;
void dfs(char cur){
    if(visited.count(cur)) return;
    visited.insert(cur);
    for(char c : graph[cur])
        dfs(c);
}

int main() {
    int t;
    char n;
    string in;
    cin >> t;
    while(t--){
        visited.clear();
        graph.clear();
        cin >> n;
        cin.ignore();
        while(getline(cin,in), !in.empty()){
            graph[in[0]].insert(in[1]);
            graph[in[1]].insert(in[0]);
        }
        int res = 0;
        for(char c='A';c<=n;c++)
            if(!visited.count(c))
                dfs(c),res++;
        printf("%d\n",res);
        if(t) printf("\n");
    }
}
