#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

typedef long long ll;


void solve() {
	ll a, b;
	int tc= 1;
	while(cin >> a >> b, (a+b)) {
		ll nc2_a = a*(a-1)/2, nc2_b = b*(b-1)/2; // number of pairs in each row
		// 1 pair from a & 1 pair from b = 1 intersection
		cout << "Case " << tc++ << ": ";
		cout << nc2_a * nc2_b << "\n";
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
