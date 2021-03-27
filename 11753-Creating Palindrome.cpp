#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

int tc=1;
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> seq(n);
	for(int i=0;i<n;i++) cin >> seq[i];

	function<int(int,int,int)> go = [&](int l, int r, int c) {
		if(c>k) return n+1;
		else if(l>=r) return c;
		if(seq[l] == seq[r]) return go(l+1, r-1, c);
		return min(go(l+1,r,c+1), go(l,r-1,c+1));
	};

	int diff = go(0, n-1, 0);
	cout << "Case " << tc++ << ": ";
	if(diff==0) cout << "Too easy\n";
	else if(diff>k) cout << "Too difficult\n";
	else cout << diff << "\n";
}


int main() {
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
}
