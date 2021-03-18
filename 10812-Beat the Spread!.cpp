#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();
typedef long long ll;

const string IMP = "impossible";
void solve() {
	ll s, d;
	cin >> s >> d;
	ll a2 = s+d;
	if(a2%2) {
		cout << IMP << "\n";
		return;
	}
	ll a = a2/2;
	ll b = s-a;
	if(b<0) {
		cout << IMP << "\n";
		return;
	}
	cout << a << " " << b << "\n";
}

int main() {
    int t=1;
	  cin >> t;
    while(t--) {
        solve();
    }
}

