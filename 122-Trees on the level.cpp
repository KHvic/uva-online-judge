#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

pair<int,string> process(string& s) {
	int split = find(all(s), ',') - s.begin();
	string s1 = s.substr(1, split-1);
	string s2 = s.substr(split+1, s.size() - split - 2);
	return {stoi(s1), s2};
}

void solve() {
	string s;
	while(cin >> s) {
		map<string, int> vmap;
		int cnt = 0;
		while(s != "()") {
			auto[v, path] = process(s);
			cnt++;
			vmap[path] = v;
			cin >> s;
		}
		vector<int> res;
		if(vmap.count("")) {
			queue<string> q;
			q.push("");
			while(!q.empty()) {
				auto top = q.front(); q.pop();
				res.push_back(vmap[top]);
				string left = top+"L", right = top+"R";
				if(vmap.count(left)) q.push(left);
				if(vmap.count(right)) q.push(right);
			}
		}
		if(res.size() != cnt) {
			cout << "not complete\n";
		} else {
			for(int i=0;i<cnt;i++) cout << res[i] << " \n"[i==cnt-1];
		}
	}
}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
