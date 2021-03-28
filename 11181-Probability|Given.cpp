#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(6); cin.tie(nullptr); return 0; }

int __fastio = fastio();

int tc = 1;
void solve() {
	int n, r;
	while(cin >> n >> r, (n+r)) {
		// P(buy_i | r) = P(buy_i & r) / P(r)
		int lim = 1<<n;
		double prob_r = 0;
		vector<double> probs(n), prob_buyi_and_r(n);
		for(int i=0;i<n;i++) cin >> probs[i];
		// also can use dp to solve with better time complexity
		// O(n*2^n) => O(n^2*r)
		for(int i=0;i<lim;i++) {
			int bits = __builtin_popcount(i);
			if(bits != r) continue;
			// compute probability of this event
			double prob = 1;
			for(int j=0;j<n;j++) {
				if(i & (1<<j)) prob *= probs[j];
				else prob *= 1.0 - probs[j];
			}
			prob_r += prob;
			for(int j=0;j<n;j++)
				if(i & (1<<j))
					prob_buyi_and_r[j] += prob;
		}
		cout << "Case " << tc++ << ":\n";
		for(int i=0;i<n;i++) cout << prob_buyi_and_r[i] / prob_r << "\n";
	}
}

int main() {
	solve();
}
