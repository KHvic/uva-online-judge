#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

typedef long long ll;
constexpr ll mod = 2000000011;
ll powe(ll x, ll e) {
	ll res = 1;
	while(e) {
		if(e&1) res = x*res%mod;
		e >>= 1;
		x = x*x%mod;
	}
	return res;
}

int main() {
    int t=1;
	cin >> t;
    for(int tc=1;tc<=t;tc++) {
		ll x;
		cin >> x;
        ll v = x<=2 ? 1 : powe(x, x-2);
		cout << "Case #" << tc << ": ";
		cout << v << "\n";
    }
}
