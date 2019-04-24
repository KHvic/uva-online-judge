#include <bits/stdc++.h>
using namespace std;

int main() {
    string in;
    string title;
    while(getline(cin,in),in != "0"){
        title = in;
        // dict is the personToProj map
        unordered_map<string,string> dict;
        unordered_set<string> banned;
        unordered_map<string,int> cnt;
        while(getline(cin,in),in != "1"){
            if(isupper(in[0])) {
                title = in;
                cnt[in] = 0;
            }
            else {
                if(banned.count(in)) continue;
                else if(dict.count(in) && title != dict[in]){
                    banned.insert(in);
                } else {
                    dict[in] = title;
                }
            }
        }
        for(auto& p : dict){
            if(!banned.count(p.first)) cnt[p.second]++;
        }
        vector<pair<int,string>> res;
        for(auto& p : cnt) res.push_back({p.second,p.first});
        sort(res.begin(),res.end(),[](pair<int,string>& a,pair<int,string>& b){
             if(a.first != b.first) return a.first>b.first;
             return a.second<b.second;
             });
        for(auto it=res.begin(); it!=res.end();it++)
            cout << it->second << " " << it->first << endl;
    }
}
