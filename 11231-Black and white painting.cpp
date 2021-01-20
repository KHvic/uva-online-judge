#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m, k;
	while(cin >> n >> m >> k, (n+m+k) != 0) {
		int rleft = max(0, n-7);
		// compute number of white a & black b on last column
		int a = rleft/2, b = rleft-a;
		if(k) swap(a, b); // white more 1
		int cleft = max(0, m-7);
		int a2 = cleft/2, b2 = cleft-a2;
		ll res = 1LL*a*b2 + 1LL*b*a2;
		cout << res << "\n";
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
