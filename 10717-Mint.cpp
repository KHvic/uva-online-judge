#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

typedef long long ll;

ll lcm(ll a, ll b) {
	return a*(b/__gcd(a,b));
}

void solve() {
	int n, t;
	while(cin >> n >> t, (n+t)) {
		vector<ll> coins(n);
		for(int i=0;i<n;i++) cin >> coins[i];
		while(t--) {
			ll tar;
			cin >> tar;
			ll mn = 0, mx = 1e9;
			for(int i=0;i<n;i++) {
				for(int j=i+1;j<n;j++) {
					for(int k=j+1;k<n;k++) {
						for(int l=k+1;l<n;l++) {
							ll cm = lcm(coins[i], lcm(coins[j], lcm(coins[k], coins[l])));
							ll v = tar/cm;
							ll low = v*cm, high = (v+1)*cm;
							if(low == tar) high = low;
							mn = max(low, mn);
							mx = min(high, mx);
						}
					}
				}
			}
			cout << mn << " " << mx << "\n";
		}
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
