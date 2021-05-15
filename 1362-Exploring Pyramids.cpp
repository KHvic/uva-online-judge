 #include <bits/stdc++.h>
 using namespace std;
 int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
 int __fastio = fastio();


 typedef long long ll;
 constexpr ll mod = 1e9;
 int main(){
     string s;
     while(cin >> s) {
        int n = s.size();
        vector<vector<ll>> dp(n, vector<ll>(n));
        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int l=1;l<n;l++) {
            for(int i=0;i+l<n;i++) {
                int j = i+l;
                if(s[i] == s[j]) {
                    for(int k=i+1;k<=j;k++) {
                        if(s[i] == s[k]) {
                            dp[i][j] += dp[i+1][k-1] * dp[k][j];
                            dp[i][j] %= mod;
                        }
                    }
                }
            }
        }
        cout << dp[0][n-1] << "\n";
     }
 }
