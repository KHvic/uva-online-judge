#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

typedef long long ll;

int main() {
    ll n;
    while(cin >> n) {
		ll res = n*n*(n+1)*(n+1)/4;
		cout << res << "\n";
    }
}
