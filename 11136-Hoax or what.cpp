#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,b,v;
    while(cin >> n, n){
        long long cost = 0;
        multiset<int> rb;
        for(int i=0;i<n;i++){
            cin >> b;
            while(b--){
                cin >> v;
                rb.insert(v);
            }
            cost += *(--rb.end()) - *(rb.begin());
            rb.erase(prev(rb.end()));
            rb.erase(rb.begin());
        }
        cout << cost << endl;
    }
}
