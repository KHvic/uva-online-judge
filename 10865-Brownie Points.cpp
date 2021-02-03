#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

typedef long long ll;
typedef pair<ll, ll> ii;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
	int n;
	while(cin >> n, n) {
		vector<ii> pts(n);
		for(int i=0;i<n;i++) cin >> pts[i].fi >> pts[i].se;
		auto [mx, my] = pts[n/2];
		int a = 0, b = 0;
		for(auto&[x, y] : pts) {
			if(x == mx || y == my) continue;
			bool left = x < mx;
			bool btm = y < my;
			if(left == btm) a++;
			else b++;
		}
		cout << a << " " << b << "\n";
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
