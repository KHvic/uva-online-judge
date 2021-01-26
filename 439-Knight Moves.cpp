#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
void solve() {
	string a, b;
	while(cin >> a) {
		cin >> b;
		int x1,x2,y1,y2;
		x1 = a[0]-'a', x2 = b[0]-'a';
		y1 = a[1]-'1', y2 = b[1]-'1';
		bool vis[8][8];
		memset(vis, 0, sizeof vis);
		queue<pair<int, int>> q;
		int steps = 0;
		vis[x1][y1] = true;
		q.push({x1,y1});

		while(!q.empty()) {
			for(int l=q.size();l>0;l--) {
				auto& [x,y] = q.front(); q.pop();
				if(x==x2 && y==y2) {
					cout << "To get from " << a << " to " << b << " takes " << steps << " knight moves.\n";
					goto out;
				}
				for(auto& d : dirs) {
					int nx = d[0]+x, ny = d[1]+y;
					if(nx<0||nx>=8||ny<0||ny>=8||vis[nx][ny]) continue;
					vis[nx][ny] = true;
					q.push({nx, ny});
				}
			}
			steps++;
		}
out:
		continue;
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
