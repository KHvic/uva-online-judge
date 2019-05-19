#include <bits/stdc++.h>
using namespace std;

void dfs(int idx,vector<string>& cur,vector<string>& topics,
         unordered_map<string,unordered_set<string>>& unallowed,int& s){
    if(cur.size() == s){
        cout << cur[0];
        for(int i=1;i<cur.size();i++) cout << " " << cur[i];
        cout << endl;
        return;
    }
    for(int i=idx;i<topics.size();i++){
        string& topic = topics[i];
        bool valid = true;
        for(auto& prev : cur)
            if(unallowed[prev].count(topic)){
                valid = false; break;
            }
        if(!valid) continue;
        cur.push_back(topic);
        dfs(i+1,cur,topics,unallowed,s);
        cur.pop_back();
    }
}

int main()
{
    int n,t,p,s;
    string in,in2;
    cin >> n;
    int tc=1;
    while(n--){
        cin >> t >> p >> s;
        vector<string> topics;
        vector<string> cur;
        unordered_map<string,unordered_set<string>> unallowed;
        for(int i=0;i<t;i++){
            cin >> in;
            transform(in.begin(),in.end(),in.begin(),::toupper);
            topics.push_back(in);
        }
        for(int i=0;i<p;i++){
            cin >> in >> in2;
            transform(in.begin(),in.end(),in.begin(),::toupper);
            transform(in2.begin(),in2.end(),in2.begin(),::toupper);
            unallowed[in].insert(in2);
            unallowed[in2].insert(in);
        }
        sort(topics.begin(),topics.end(),[](const string& a,const string& b){
                if(a.length() == b.length()) return a < b;
                return a.length() > b.length();
             });
        printf("Set %d:\n",tc++);
        dfs(0,cur,topics,unallowed,s);
        cout << endl;
    }
}
