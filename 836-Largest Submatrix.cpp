#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    string in;
    cin >> t;
    while(t--){
        cin >> in;
        n = in.length();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            if(i>0) { cin >> in; }
            for(int j=0;j<n;j++){
                dp[i][j] += (in[j]-'0');
                if(i) dp[i][j] += dp[i-1][j];
                if(j) dp[i][j] += dp[i][j-1];
                if(i&&j) dp[i][j] -= dp[i-1][j-1];
            }
        }
        int best = 0;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            for(int k=i;k<n;k++) for(int l=j;l<n;l++){
                int fullSeq = (k-i+1)*(l-j+1);
                int cur = dp[k][l];
                if(i) cur -= dp[i-1][l];
                if(j) cur -= dp[k][j-1];
                if(i&&j) cur += dp[i-1][j-1];
                if(fullSeq == cur) best = max(fullSeq,best);
            }
        }
        cout << best << endl;
        if(t) cout << endl;
    }
}
