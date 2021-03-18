#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();
typedef long long ll;

void solve() {
	ll a, b;
	while(cin >> a) {
		cin >> b;
		cout << (a^b) << "\n";
	}
}

int main() {
  solve();
}
