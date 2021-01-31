#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

typedef long long ll;
typedef pair<ll, ll> ii;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

struct UF {
    vector<int> p, rank, size;
    int cnt;
    UF(int N): cnt(N) {
        p = rank = size = vector<int>(N, 1);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int find(int i) {
        return p[i] == i ? i : p[i] = find(p[i]);
    }
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
    void join(int i, int j) {
        if (connected(i, j)) return;
        cnt--;
        int x = find(i), y = find(j);
        if (rank[x] > rank[y]) {
            p[y] = x;
            size[x] += size[y];
        } else {
            p[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};

void solve() {
	int n;
	cin >> n;
	vector<ii> towns(n);
	for(int i=0;i<n;i++) cin >> towns[i].fi >> towns[i].se;
	int m;
	cin >> m;
	UF uf(n);
	while(m--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf.join(a, b);
	}
	vector<vector<ll>> edges;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			auto&[x,y] = towns[i];
			auto&[x2,y2] = towns[j];
			ll dx = x-x2, dy = y-y2;
			edges.push_back({dx*dx+dy*dy, i, j});
		}
	}
	sort(all(edges));
	vector<pair<int, int>> res;
	for(auto& e : edges) {
		int x = e[1], y = e[2];
		if(!uf.connected(x,y)) {
			uf.join(x,y);
			res.emplace_back(x+1, y+1);
		}
	}
	if(res.empty()) {
		cout << "No new highways need\n";
	} else {
		for(auto&[x,y] : res) cout << x << " " << y << "\n";
	}
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
