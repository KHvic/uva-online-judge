#include <bits/stdc++.h>
using namespace std;

int main() {
    int v;
    int a,b,c,d,e;
    map<vector<int>,int> cnt;
    while(cin >> v, v){
        cnt.clear();
        int high = 0;
        while(v--){
            cin >> a >> b >> c >> d >> e;
            vector<int> input={a,b,c,d,e};
            sort(input.begin(),input.end());
            high = max(high,++cnt[input]);
        }
        int res = 0;
        for(auto& p : cnt) {
            if(p.second == high) res++;
        }
        cout << res*high << endl;
    }
}
