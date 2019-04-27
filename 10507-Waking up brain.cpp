#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    string in;
    while(scanf("%d",&n) != EOF){
        unordered_set<char> waked;
        unordered_map<char,unordered_set<char>> graph;
        int y = 0;
        scanf("%d",&m);
        cin >> in;
        for(auto& c : in) waked.insert(c);
        for(int i=0;i<m;i++){
            cin >> in;
            graph[in[0]].insert(in[1]);
            graph[in[1]].insert(in[0]);
        }
        while(waked.size() != n){
            y++;
            vector<char> completed;
            for(auto& p : graph){
                int cnt=0;
                for(auto& neighbor : p.second){
                    if(waked.count(neighbor)) cnt++;
                }
                if(cnt>=3 || waked.count(p.first))
                    completed.push_back(p.first);
            }
            if(completed.empty()) break;
            for(auto& c : completed) { waked.insert(c); graph.erase(c);}
        }
        if(waked.size() != n) cout << "THIS BRAIN NEVER WAKES UP" << endl;
        else cout << "WAKE UP IN, " << y << ", YEARS" << endl;
    }
}
