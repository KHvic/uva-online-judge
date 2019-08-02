#include <bits/stdc++.h>
using namespace std;

// idea: check if all source to app requirements is fulfilled from flowing

unordered_map<char,unordered_map<char,int>> graph;
unordered_map<char,char> parent;
int flow = 0;

void augment(char cur, int minEdge){
    if(cur == '-') {
        flow = minEdge;
        return;
    } else if(parent.count(cur)){
        char par = parent[cur];
        augment(par,min(minEdge,graph[par][cur]));
        graph[par][cur] -= flow;
        graph[cur][par] += flow;
    }
}

int main()
{
    string in,app,coms;
    while(getline(cin,in)){
        graph.clear();
        // '-' for source, '*' for sink
        for(char c='0';c<='9';c++) graph[c]['*'] = 1;
        do{
            istringstream iss(in);
            iss >> app >> coms;
            graph['-'][app[0]] = app[1]-'0'; // set number of users
            for(int i=0;i<coms.length()-1;i++)
                graph[app[0]][coms[i]] = 1; // connect app to computer
        } while(getline(cin,in),in!="");
        // edmond karp
        while(1){
            flow = 0;
            unordered_set<char> visited;
            visited.insert('-');
            queue<char> bfs;
            bfs.push('-');
            parent.clear();
            while(!bfs.empty()){
                int cur = bfs.front(); bfs.pop();
                if(cur == '*') break;
                for(auto& neigh : graph[cur])
                    if(neigh.second > 0 && !visited.count(neigh.first)){
                        visited.insert(neigh.first);
                        bfs.push(neigh.first);
                        parent[neigh.first] = cur;
                    }
            }
            augment('*',1e7);
            if(flow == 0) break;
        }
        bool valid = true;
        for(char c='A';c<='Z' && valid;c++)
            if(graph['-'][c])
                valid = false;
        if(!valid) printf("!\n");
        else {
            string res = "__________";
            for(char a='A';a<='Z';a++)
                for(char c='0';c<='9';c++)
                    if(graph[c][a] != 0)
                        res[c-'0'] = a;
            cout << res << endl;
        }
    }
}
