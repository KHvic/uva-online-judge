#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();

#define all(x) (x).begin(), (x).end()

struct UF {
    int cnt;
    vector<int> p, rank, size;
    UF(int N): cnt{N} {
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
	int n, m;
	cin >> n >> m;
	string a, b;
	int v;
	map<string,int> idxmap;
	vector<tuple<int,int,int>> edges;
	int idx = 0;
	auto getIdx = [&](string& x) {
		return idxmap.count(x) ? idxmap[x] : idxmap[x] = idx++;
	};
	for(int i=0;i<m;i++) {
		cin >> a >> b >> v;
		int v1 = getIdx(a), v2 = getIdx(b);
		edges.emplace_back(v,v1,v2);
	}
	UF uf(n);
	int res = 0;
	sort(all(edges));
	for(auto&[d,a,b] : edges) {
		if(!uf.connected(a,b)) {
			res += d;
			uf.join(a,b);
		}
	}
	cout << res << "\n";
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
