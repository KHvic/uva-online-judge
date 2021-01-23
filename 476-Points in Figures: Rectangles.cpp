#include <bits/stdc++.h>
using namespace std;

void solve() {
	char x;
	double a,b,c,d;
	vector<ii> rects;
	while(cin >> x, x != '*') {
		cin >> a >> b >> c >> d;
		rects.emplace_back(a, b, c, d);
	}
	int idx = 1;
	while(cin >> a >> b, a!= 9999.9 || b!=9999.9) {
		bool ok = false;
		for(int i=0;i<rects.size();i++) {
			auto&[z,x,c,v] = rects[i];
			bool withinX = a > z && a < c;
			bool withinY = b > v && b < x;
			if(withinX && withinY) {
				ok = true;
				cout << "Point " << idx << " is contained in figure " << (i+1) << "\n";
			}
		}
		if(!ok) cout << "Point " << idx << " is not contained in any figure\n";
		idx++;
	}

}

int main() {
    int t=1;
    while(t--) {
        solve();
    }
}
