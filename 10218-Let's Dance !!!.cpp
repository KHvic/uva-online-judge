#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();


constexpr int N = 101;
double pascal[N][N]; // n choose k
void initPascal() {
	for(int i=0;i<N;i++) {
		pascal[i][0] = 1;
		for(int j=1;j<=i;j++) {
			pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
		}
	}
}

void solve() {
	int m, w, c;
	while(cin >> m >> w >> c, (m+w)) {
		double res = 0;
		double woman = (double)w/(m+w);
		double man = 1 - woman;
		for(int i=0;i<=c;i+=2) {
			int count_woman = c - i;
			double prob = pow(woman, count_woman) * pow(man, i); // * note one person is allowed to receive more than once
			double ways = pascal[c][i]; // ways to select i candies from c
			res += prob*ways;
		}
		cout << res << "\n";
	}
}

int main() {
	initPascal();
	solve();
}
