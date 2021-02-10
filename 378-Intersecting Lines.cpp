#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(2); cin.tie(nullptr); return 0; }

int __fastio = fastio();

void solve() {
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int a1 = y2-y1;
	int b1 = x1 -x2;
	int c1 =  y1*x2 - x1*y2;
	int a2 = y4 -y3;
	int b2 = x3 -x4;
	int c2 =  y3*x4 - x3*y4;
	int m = (a1*b2 - b1*a2);
	int x = (b1*c2 - b2*c1);
	int y = (c1*a2 - c2*a1);
	if(m==0) {
		if(x||y) cout << "NONE\n";
		else cout << "LINE\n";
	} else {
		cout << "POINT " << (double)x/m << " " << (double)y/m << "\n";
	}
}

int main() {
    int t=1;
	cin >> t;
	cout << "INTERSECTING LINES OUTPUT\n";
    while(t--) {
        solve();
    }
	cout << "END OF OUTPUT\n";
}
