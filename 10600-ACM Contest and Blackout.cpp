#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

struct UF {
	vector<int> pars;
	int cnt;
	UF(int N):cnt(N) {
		pars.assign(N, 0);
		for(int i=0;i<N;i++) pars[i] = i;
	}
	bool connected(int a, int b) {
		return find(a) == find(b);
	}
	int find(int x) {
		return pars[x] == x ? x : pars[x] = find(pars[x]);
	}
	void join(int a, int b) {
		if(connected(a, b)) return;
		a = find(a), b = find(b);
		pars[b] = a;
		cnt--;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges;
	for(int i=0;i<m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edges.emplace_back(c, a, b);
	}
	sort(all(edges));

	vector<int> mstIndex;
	int mst1 = 0, mst2 = 1e9;
	UF uf(n);
	for(int i=0;i<m;i++) {
		auto&[c,a,b] = edges[i];
		if(uf.connected(a,b)) continue;
		mst1 += c;
		mstIndex.push_back(i);
		uf.join(a, b);
	}
	for(int b : mstIndex) {
		uf = UF(n);
		int cost = 0;
		for(int i=0;i<m;i++) {
			if(b == i) continue;
			auto&[c,a,b] = edges[i];
			if(uf.connected(a,b)) continue;
			cost += c;
			uf.join(a, b);
		}
		if(uf.cnt == 1) mst2 = min(mst2, cost);
	}
	cout << mst1 << " " << mst2 << "\n";
}

int main() {
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
}
