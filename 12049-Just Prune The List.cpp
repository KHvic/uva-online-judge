#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,m,v;
    cin >> t;
    while(t--){
        cin >> n >> m;
        unordered_multiset<int> s;
        int res = 0;
        while(n--){
            cin >> v;
            s.insert(v);
        }
        while(m--){
            cin >> v;
            auto it = s.find(v);
            if(it==s.end()) res++;
            else s.erase(it);
        }
        res += s.size();
        cout << res << endl;
    }
}
