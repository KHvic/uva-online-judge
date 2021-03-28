#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(6); cin.tie(nullptr); return 0; }

int __fastio = fastio();

typedef long long ll;

// observation: sum(2^i) from 0 to i <= 2^(i+1), thus only last round matter
void solve() {
	int n, k;
	while(cin >> n >> k, (n+k)) {
		vector<ll> vals(n);
		for(int i=0;i<n;i++) {
			int v;
			for(int j=0;j<k;j++) cin >> v;
			vals[i] = v;
		}
		ll sum = accumulate(vals.begin(), vals.end(), 0LL);
		for(int i=0;i<n;i++) {
			ll gcd = __gcd(sum, vals[i]);
			ll left = vals[i]/gcd, right = sum/gcd;
			cout << left << " / " << right << "\n";
		}
	}
}

int main() {
	solve();
}
