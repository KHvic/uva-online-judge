#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

void solve() {
	int n;
	cin >> n;
	vector<int> ranks(n);
	for(int i=0;i<n;i++) cin >> ranks[i], ranks[i]--;
	vector<vector<int>> depends(n, vector<int>(n));
	for(int i=1;i<n;i++) {
		for(int j=0;j<i;j++) depends[ranks[i]][ranks[j]] = true;
	}
	vector<int> res;
	int m, a, b;
	cin >> m;
	for(int i=0;i<m;i++) {
		cin >> a >> b;
		a--; b--;
		swap(depends[a][b], depends[b][a]);
	}
	vector<vector<int>> out(n);
	vector<int> deg(n);
	queue<int> topo;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) if(depends[i][j]) {
			out[j].push_back(i);
			deg[i]++;
		}
		if(deg[i] == 0) topo.push(i);
	}
	while(!topo.empty()) {
		int top = topo.front(); topo.pop();
		res.push_back(top + 1);
		for(int x : out[top]) {
			if(--deg[x] == 0) topo.push(x);
		}
	}
	if(res.size() != n) cout << "IMPOSSIBLE\n";
	else {
		for(int i=0;i<n;i++) cout << res[i] << " \n"[i==n-1];
	}
}

int main() {
    int t=1;
	cin >> t;
    while(t--) {
        solve();
    }
}
