#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(6); cin.tie(nullptr); return 0; }

int __fastio = fastio();

void solve() {
	int n;
	while(cin >> n, n) {
		vector<int> vals(n);
		int total = n*(n-1)/2;
		for(int i=0;i<n;i++) cin >> vals[i];
		int cnt = 0;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++)
				if(__gcd(vals[i], vals[j]) == 1) cnt++;
		}
		if(cnt == 0) {
			cout << "No estimate for this data set.\n";
			continue;
		}
		double res = sqrt(6.0/cnt*total);
		cout << res << "\n";
	}
}

int main() {
        solve();
}
