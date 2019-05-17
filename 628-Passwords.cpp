#include <bits/stdc++.h>
using namespace std;

void dfs(int i, string& rule, vector<string>& dict,string& cur){
    if(i == rule.length()){
        cout << cur << endl;
        return;
    }
    if(rule[i] == '0'){
        for(int j=0;j<10;j++){
            cur += (j+'0');
            dfs(i+1,rule,dict,cur);
            cur.pop_back();
        }
    } else {
        int curlen = cur.length();
        for(auto& w : dict){
            cur += w;
            dfs(i+1,rule,dict,cur);
            cur.resize(curlen);
        }
    }
}

int main()
{
    int n;
    string in;
    while(cin >> n){
        vector<string> dict;
        for(int i=0;i<n;i++){
            cin >> in;
            dict.push_back(in);
        }
        int r;
        cin >> r;
        printf("--\n");
        for(int i=0;i<r;i++){
            cin >> in;
            string cur = "";
            dfs(0,in,dict,cur);
        }
    }
}
