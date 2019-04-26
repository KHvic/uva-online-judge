#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,v;
    while(scanf("%d %d",&n,&m),n || m){
        unordered_set<int> s;
        int res = 0;
        while(n--){
            cin>>v;
            s.insert(v);
        }
        while(m--){
            cin>>v;
            if(s.count(v)) res++;
        }
        cout << res << endl;
    }
}
