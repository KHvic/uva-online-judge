#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,v;
    cin >> t;
    while(t--){
        cin >> n;
        int sum = 0;
        multiset<int> prev;
        while(n--){
            cin >> v;
            auto upper = prev.upper_bound(v);
            sum += distance(prev.begin(),upper);
            prev.insert(v);
        }
        cout << sum << endl;
    }
}
