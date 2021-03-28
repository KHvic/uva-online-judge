#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(4); cin.tie(nullptr); return 0; }

int __fastio = fastio();

void solve() {
	int n;
	double p;
	int i;
	cin >> n >> p >> i;
	if(p==0) {
		cout << p << "\n";
		return;
	}
  // solve for F[i] = prob-win + prob-lose = (1-P)^(i-1) * P + (1-P)^n * F[i]
	double res = pow((1.0 - p), i-1) * p / (1.0 - pow(1.0 - p, n));
	cout << res << "\n";
}

int main() {
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
}
