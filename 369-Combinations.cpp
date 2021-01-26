#include <bits/stdc++.h>
using namespace std;

constexpr int N = 101;
ll dp[N][N];
void solve() {
	for(int i=0;i<N;i++) {
		dp[i][0] = 1;
		for(int j=1;j<=i;j++) {
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
	int n, m;
	while(cin >> n >> m, (n+m)) {
		cout << n << " things taken " << m << " at a time is " << dp[n][m] << " exactly.\n";
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
