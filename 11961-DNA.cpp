#include <bits/stdc++.h>
using namespace std;

string permute = "ACGT";

void dfs(int diff,int k,string& cur, string& ori,vector<string>& res){
    int idx = cur.length();
    if(diff > k) return;
    if(idx == ori.length()){
        res.push_back(cur);
        return;
    }
    for(char& c : permute){
        cur += c;
        dfs(diff + (c!=ori[idx]),k,cur,ori,res);
        cur.pop_back();
    }
}

int main()
{
    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        string in;
        cin >> in;
        string cur = "";
        vector<string> res;
        dfs(0,k,cur,in,res);
        cout << res.size() << endl;
        for(auto& s : res)
            cout << s << endl;
    }
}
