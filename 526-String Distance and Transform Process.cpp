#include <bits/stdc++.h>

using namespace std;
string a,b;
int offset,steps;

void print(int i, int j, vector<vector<int>>& dp){
    if(i==0 && j==0) return;
    else if(i!=0 && j!=0 && a[i-1] == b[j-1]){
        print(i-1,j-1,dp);
    } else if(j!=0 && dp[i][j] == dp[i][j-1]+1){
        print(i,j-1,dp);
        offset++;
        printf("%d Insert %d,%c\n",++steps,i+offset,b[j-1]);
    } else if(i!=0 && dp[i][j] == dp[i-1][j]+1){
        print(i-1,j,dp);
        printf("%d Delete %d\n",++steps,i+offset);
        offset--;
    } else if(dp[i][j] == dp[i-1][j-1]+1){
        print(i-1,j-1,dp);
        printf("%d Replace %d,%c\n",++steps,i+offset,b[j-1]);
    }
}

int main()
{
    bool printed = false;
    while(getline(cin,a)){
        if(printed) printf("\n");
        printed = true;
        getline(cin,b);
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1));
        for(int i=0;i<=b.length();i++) dp[0][i] = i;
        
        for(int i=0;i<a.length();i++){
            dp[i+1][0] = i+1;
            for(int j=0;j<b.length();j++){
                if(a[i] == b[j]){
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    dp[i+1][j+1] = min(dp[i][j], // edit
                                       min(dp[i][j+1], // delete a[i+1]
                                       dp[i+1][j]))+1; // insert b[j+1]
                }
            }
        }
        printf("%d\n",dp[a.length()][b.length()]);
        offset = steps = 0;
        print(a.length(),b.length(),dp);
    }
}
