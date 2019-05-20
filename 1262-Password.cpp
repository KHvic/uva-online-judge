#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

bool dfs(string& cur,vector<set<char>>& cols,const int& k){
    int idx = cur.length();
    if(idx == 5){
        if(++cnt == k){
            cout << cur << endl;
            return true;
        }
        return false;
    }
    for(auto& c : cols[idx]){
        cur += c;
        if(dfs(cur,cols,k)) return true;
        cur.pop_back();
    }
    return false;
}

int main()
{
    int t,k;
    string in;
    cin >> t;
    while(t--){
        cin >> k;
        vector<unordered_set<char>> temp(5);
        vector<set<char>> cols(5);
        cnt = 0;
        for(int l=0;l<2;l++)
        for(int i=0;i<6;i++){
            cin >> in;
            for(int j=0;j<5;j++){
                if(l==0) temp[j].insert(in[j]);
                else if(temp[j].count(in[j])){
                    cols[j].insert(in[j]);
                }
            }
        }
        string cur = "";
        if(!dfs(cur,cols,k)) cout << "NO" << endl;
    }
}
