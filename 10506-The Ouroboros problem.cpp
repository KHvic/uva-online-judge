#include <bits/stdc++.h>
using namespace std;
// euler circuit
// De Bruijn path len = n^m+m-1
// circuit len = n^m
int m,n;
int len;

bool dfs(string& cur,unordered_set<string>& visited){
    if(cur.size() == len){
        vector<string> revert;
        for(int i=1;i<m;i++){
            string nxt = cur.substr(cur.size()-m+i) + cur.substr(0,i);
            if(!visited.count(nxt)){
                visited.insert(nxt);
                revert.push_back(nxt);
            } else {
                for(auto& s : revert) visited.erase(s);
                return false;
            }
        }
        cout << cur << endl;
        return true;
    }
    string prev = cur.substr(cur.length()-m+1);
    for(int i=0;i<n;i++){
        string nxt = prev + (char)('0'+i);
        if(!visited.count(nxt)){
            visited.insert(nxt);
            cur += (char)('0'+i);
            if(dfs(cur,visited)) return true;
            cur.pop_back();
            visited.erase(nxt);
        }
    }
    return false;
}

int main()
{
    while(cin >> m){
        cin >> n;
        len = pow(n,m);
        unordered_set<string> visited;
        string cur(m-1,'0');
        dfs(cur,visited);
    }
}
