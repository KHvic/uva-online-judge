#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }

int __fastio = fastio();

int main() {
	string in;
	while(getline(cin, in)) {
		istringstream iss(in);
		vector<int> coeff, xs;
		int c;
		while(iss >> c) coeff.push_back(c);
		getline(cin, in);
		iss = istringstream(in);
		while(iss >> c) xs.push_back(c);

		for(int i=0;i<xs.size();i++) {
			int x = 1;
			int sum = 0;
			for(int j=coeff.size()-1;j>=0;j--) {
				sum += coeff[j]*x;
				x *= xs[i];
			}
			cout << sum << " \n"[i==xs.size()-1];
		}
	}
}
