#include<bits/stdc++.h>
using namespace std;
vector<char> vars;
unordered_set<char> used;
unordered_map<char,int> indegree;
unordered_map<char,unordered_set<char>> graph;

void backtrack(string& cur,vector<string>& res){
    if(cur.size() == vars.size()){
        res.push_back(cur);
        return;
    }
    for(auto& var : vars){
        if(used.count(var) || indegree[var]!=0) continue;
        cur += var;
        used.insert(var);
        for(auto& neighbor : graph[var]){
            indegree[neighbor]--;
        }
        backtrack(cur,res);
        cur.pop_back();
        used.erase(var);
        for(auto& neighbor : graph[var]){
            indegree[neighbor]++;
        }
    }
}

int main()
{
    int t;
    string in;
    cin >> t;
    cin.ignore();
    while(t--){
        cin.ignore();
        vars.clear();
        used.clear();
        indegree.clear();
        graph.clear();
        getline(cin,in);
        istringstream iss(in);
        while(iss >> in){
            vars.push_back(in[0]);
        }
        getline(cin,in);
        iss.clear();
        iss.str(in);
        while(iss >> in){
            char a = in[0];
            char b = in[2];
            if(!graph[a].count(b)){
                indegree[b]++;
                graph[a].insert(b);
            }
        }
        vector<string> res;
        string cur = "";
        backtrack(cur,res);
        sort(res.begin(),res.end());
        if(res.empty())
            printf("NO\n");
        else{
            for(auto& r : res){
                printf("%c",r[0]);
                for(int i=1;i<r.size();i++) printf(" %c",r[i]);
                printf("\n");
            }
        }
        if(t) printf("\n");
    }
}
