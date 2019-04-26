#include <bits/stdc++.h>
using namespace std;

int dfs( unordered_map<char,unordered_set<char>>& graph, unordered_set<char>& visited, char n){
    if(visited.count(n)) return 0;
    int res = 1;
    visited.insert(n);
    for(char child : graph[n])
        res += dfs(graph,visited,child);
    return res;
}

int main() {
    int t;
    cin >> t;
    string in;
    while(t--){
        unordered_map<char,unordered_set<char>> graph;
        unordered_set<char> visited;
        while(getline(cin,in), in[0] != '*'){
            char a = in[1], b = in[3];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        int acorn = 0, tree = 0;
        getline(cin,in);
        for(int i=0;i<in.length();i+=2){
            if(!visited.count(in[i])){
                if(dfs(graph,visited,in[i]) == 1) acorn++;
                else tree++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
    }
}
