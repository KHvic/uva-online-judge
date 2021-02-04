#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
	int s, p;
	cin >> s >> p;
	vector<pair<int, int>> V(p);
	for(int i=0;i<p;i++) cin >> V[i].fi >> V[i].se;
	vector<tuple<double,int,int>> edges;
	for(int i=0;i<p;i++) {
		for(int j=i+1;j<p;j++) {
			double dist = hypot(V[i].fi-V[j].fi, V[i].se - V[j].se);
			edges.emplace_back(dist, i, j);
		}
	}
	sort(all(edges));
	UF uf(p);
	int joinCnt = p-s;
	double res = 0;
	for(auto&[d,x,y] : edges) {
		if(joinCnt <= 0) break;
		if(!uf.connected(x,y)) {
			res = d;
			joinCnt--;
			uf.join(x, y);
		}
	}
	cout << res << "\n";
}

int main() {
    int t=1;
	cin >> t;
    while(t--) {
        solve();
    }
}
