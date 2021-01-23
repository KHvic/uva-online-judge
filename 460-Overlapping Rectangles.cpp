#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c, d;
	int z, x, y, w;
	cin >> a >> b >> c >> d >> z >> x >> y >> w;
	int l = max(a, z), r = min(c, y);
	int b2 = max(b, x), t = min(d, w);

	if(l>=r || t<=b2) {
		cout << "No Overlap\n";
		return;
	}
	cout << l << " " << b2 << " " << r << " " << t << "\n";
}

int main() {
    int t=1;
	cin >> t;
	bool first = true;
    while(t--) {
		if(!first) cout << "\n";
		first = false;
        solve();
    }
}
