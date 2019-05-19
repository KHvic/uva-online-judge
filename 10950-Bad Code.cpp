#include <bits/stdc++.h>
using namespace std;
int cnt;

void dfs(int idx,string& cur,vector<pair<char,string>>& encode,string& t){
    if(idx == t.length()) {
        cnt++;
        cout << cur << endl;
        return;
    }

    while(idx<t.length() && t[idx] == '0') idx++;
    if(idx>=t.length()) return;

    for(auto& p : encode){
        if(p.second.length() > t.length()-idx) continue;
        bool valid = true;
        for(int i=0;i<p.second.length() && valid;i++){
            if(t[i+idx] != p.second[i]) valid = false;
        }
        if(valid){
            cur += p.first;
            dfs(idx+p.second.length(),cur,encode,t);
            cur.pop_back();
        }
        if(cnt>= 100) return;
    }
}

int main()
{
    int n,v,tc=1;
    char c;
    string t;
    while(cin>>n,n){
        string cur = "";
        vector<pair<char,string>> encode;
        for(int i=0;i<n;i++){
            cin >> c >> v;
            encode.push_back({c,to_string(v)});
        }
        cin >> t;
        sort(encode.begin(),encode.end());
        cnt = 0;
        printf("Case #%d\n",tc++);
        dfs(0,cur,encode,t);
        cout << endl;
    }
}
