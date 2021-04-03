#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

typedef long long ll;

const vector<vector<int>> DIRS = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for(int i=0;i<n;i++) cin >> grid[i];
	int t;
	cin >> t;
	while(t--) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;

		int dist[n][m];
		memset(dist, 0x3f, sizeof dist);
		dist[x1][y1] = 0;
		deque<pair<int, int>> dq;
		dq.push_back({x1, y1});

		int steps = 0;
		while(!dq.empty()) {
			int len = dq.size();
			while(len--) {
				auto[x,y] = dq.front(); dq.pop_front();
				if(steps > dist[x][y]) continue;

				int curr = grid[x][y] - '0';
				for(int i=0;i<8;i++) {
					int nx = x+DIRS[i][0], ny = y+DIRS[i][1];
					int cost = steps + (curr != i);
					if(nx<0 || ny<0 || nx>=n || ny>=m || cost >= dist[nx][ny]) continue;
					dist[nx][ny] = cost;
					if(curr == i) {
						len++;
						dq.push_front({nx, ny});
					} else dq.push_back({nx, ny});
				}
			}
			steps++;
		}
		cout << dist[x2][y2] << "\n";
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
