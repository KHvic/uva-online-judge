#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(4); cin.tie(nullptr); return 0; }
int __fastio = fastio();

int main(){
    double n;
    while(cin >> n, n != 0) {
        double a = floor(cbrt(n)); // largest a^3 <= n
        double dx = (n - pow(a,3)) / 3 / pow(a,2);
        cout << dx+a << "\n";
    }
}
