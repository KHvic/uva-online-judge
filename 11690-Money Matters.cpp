#include <bits/stdc++.h>
using namespace std;

int owe[10000];
int udfs[10000];

int udfsFind(int n){
    return udfs[n] == n ? n : udfsFind(udfs[n]);
}

void udfsJoin(int a, int b){
    if(udfsFind(a) == udfsFind(b)) return;
    owe[udfsFind(a)] += owe[udfsFind(b)];
    udfs[udfsFind(b)] = udfsFind(a);
}

int main() {
    int t;
    int n,m;
    int v,b;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++) {
            udfs[i] = i;
            cin >> v;
            owe[i] = v;
        }
        while(m--){
            cin >> v >> b;
            udfsJoin(v,b);
        }
        bool res = true;
        for(int i=0;i<n && res;i++) {
            if(owe[udfsFind(i)] != 0) res = false;
        }
        cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
}
