#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

constexpr int N = 10000001;
bitset<N> isprime;
vector<int> primes;
void sieve() {
	isprime.set();
	isprime[0] = isprime[1] = false;
	for(ll i=2;i<N;i++) {
		if(!isprime[i]) continue;
		primes.push_back(i);
		for(ll j=i*i;j<N;j+=i) isprime[j] = false;
	}
}

void solve() {
	ll x;
	sieve();
	while(cin >> x) {
		if(x<8) {
			cout << "Impossible.\n";
		} else {
			// Goldbach's conjecture, every even number >= 4 can be represented as two prime
			cout << 2 << " ";
			cout << (x%2 ? 3 : 2) << " ";
			x -= 4 + (x%2); // make even

			for(int y : primes) {
				if(isprime[x-y]) {
					cout << y << " " << x-y << "\n";
					break;
				}
			}
		}
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
