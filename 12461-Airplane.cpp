#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(6); cin.tie(nullptr); return 0; }

int __fastio = fastio();

void solve() {
	int n;
	while(cin >> n, n) {
		// F[1] = 1
		// F[2] = 0.5, 50% sit on his own seat
		// F[3] = 1/3*F[2] + 1/3 = 1/6 + 2/3 = 0.5
		// F[4] = 2/4*F[3] + 1/4 = 0.5
		// ..., all 0.5 when n > 1
		cout << "1/2\n";
	}
}

int main() {
	solve();
}
