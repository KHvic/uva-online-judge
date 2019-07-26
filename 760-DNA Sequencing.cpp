#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    bool first = true;
    while(getline(cin,a)){
        getline(cin,b);
        if(!first) cout << endl;
        first = false;
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1));
        set<string> res;
        int best = 0;
        // longest common substring dp
        for(int i=0;i<a.length();i++){
            for(int j=0;j<b.length();j++){
                if(a[i] == b[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    if(dp[i+1][j+1] > best){
                        best = dp[i+1][j+1];
                        res.clear();
                    }
                    if(dp[i+1][j+1] == best){
                        res.insert(a.substr(i-best+1,best));
                    }
                }
            }
        }
        if(res.empty()) cout << "No common sequence." << endl;
        else {
            for(auto& str : res)
                cout << str << endl;
        }
        getline(cin, a); //junk
    }
}
