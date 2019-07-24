#include <bits/stdc++.h>

using namespace std;
vector<string> a,b;
vector<string> res;

void reconstruct(int i,int j,vector<vector<int>>& dp){
    if(i==0 && j==0) return;
    else if(i!=0 && j!=0 && a[i-1] == b[j-1]){
        reconstruct(i-1,j-1,dp);
        res.push_back(a[i-1]);
    } else if(i!=0 && dp[i][j] == dp[i-1][j]){
        reconstruct(i-1,j,dp);
    } else if(j!=0 && dp[i][j] == dp[i][j-1]){
        reconstruct(i,j-1,dp);
    }
}

int main()
{
    string in;
    while(cin >> in){
        a.clear(); b.clear(); res.clear();
        do{
            if(in=="#") break;
            a.push_back(in);
        }while(cin>>in);
        while(cin >> in,in!="#"){
            b.push_back(in);
        }
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                if(a[i]==b[j]) dp[i+1][j+1] = dp[i][j]+1;
                else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        reconstruct(a.size(),b.size(),dp);
        for(auto& word : res){
            cout << word;
            if(&word != &res.back()) cout << " ";
        }
        cout << endl;
    }
}
