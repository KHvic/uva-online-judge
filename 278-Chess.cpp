#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, m;
    char s;
    cin >> t;
    while(t--) {
        cin >> s >> n >> m;
        int res;
        if(s=='r') {
            res = min(n, m);
        } else if(s=='Q') {
            res = min(n, m); //queen problem always have solution for n>=4
        } else if(s=='K') {
            res = ((n+1)/2) * ((m+1)/2); // 1king take four cells
        } else if(s=='k') {
           res = (n*m)%2 ? n*m/2+1 : n*m/2; // knight occupy one color
        }
        cout << res << "\n";
    }
}
