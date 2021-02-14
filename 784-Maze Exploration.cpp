#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();

vector<vector<int>> DIRS = {{1,0},{0,1},{0,-1},{-1,0}};
void solve() {
	vector<string> grid;
	string in;
	while(getline(cin, in), in[0] != '_') {
		grid.push_back(in);
	}

	stack<pair<int, int>> st;
	for(int i=0;i<grid.size();i++)
		for(int j=0;j<grid[i].size();j++)
			if(grid[i][j] == '*') {
				grid[i][j] = '#';
				st.push({i,j});
			}
	while(!st.empty()) {
		auto[x,y] = st.top(); st.pop();
		for(auto& d : DIRS) {
			int nx = d[0]+x, ny = d[1]+y;
			if(nx<0||ny<0||nx>=grid.size()||ny>=grid[nx].size()) continue;
			if(grid[nx][ny] != ' ') continue;
			grid[nx][ny] = '#';
			st.push({nx,ny});
		}
	}
	for(string& s : grid) cout << s << "\n";
	cout << in << "\n";
}

int main() {
    int t=1;
    cin >> t;
    cin.ignore();
    while(t--) {
        solve();
    }
}
