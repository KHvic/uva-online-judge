#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// dfs will work too
int bfs(vector<vector<int>>& graph, int start, vector<int>& cost) {
	int res = 0;
	int n = graph.size();
	vector<bool> vis(n);
	queue<int> q;
	vis[start] = true;
	q.push(start);
	while(!q.empty()) {
		int top = q.front(); q.pop();
		res += cost[top];
		for(int x : graph[top])
			if(!vis[x]) {
				vis[x] = true;
				q.push(x);
			}
	}
	return res;
}

void solve() {
	int v, e;
	int tc=1;
	while(cin >> v >> e, (v+e)) {
		vector<int> vals(v);
		for(int i=0;i<v;i++) cin >> vals[i];
		vector<vector<int>> graph(v), rgraph(v);
		for(int i=0;i<e;i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			graph[a].push_back(b);
			rgraph[b].push_back(a);
		}
		int q, t;
		cin >> q;
		int totalCost = accumulate(all(vals), 0);
		cout << "Case #" << tc++ << ":\n";
		while(q--) {
			cin >> t;
			t--;
			// earliest cost is all dependencies that have to finish before t
			int costBefore = bfs(rgraph, t, vals) - vals[t];
			int costAfter = bfs(graph, t, vals);
			// latest cost is allCost excluding dependecies that depends on t directly/indirectly
			int latest = totalCost - costAfter;
			cout << latest - costBefore << "\n";
		}
		cout << "\n";
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
