#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

typedef long long ll;

ll lcm(ll a, ll b) {
	return a*(b/__gcd(a,b));
}

ll cntDiv(ll x, ll d) {
	return x/d;
}

void solve() {
	ll n, m;
	while(cin >> n >> m) {
		vector<ll> nums(m);
		for(int i=0;i<m;i++) cin >> nums[i];
		ll totalDiv = 0;
		// PIE
		for(int i=1;i<(1<<m);i++) {
			ll mult = 1;
			ll sign = __builtin_popcount(i) % 2 ? 1 : -1;
			for(int j=0;j<m;j++)
				if(i&(1<<j))
					mult = lcm(mult, nums[j]);
			totalDiv += sign*cntDiv(n, mult);
		}
		cout << (n-totalDiv) << "\n";
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
