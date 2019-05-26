#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    while(scanf("%d",&n),n){
        int remaining = n;
        unordered_map<int,unordered_multiset<int>> fromTo;
        for(int i=0;i<n;i++){
            cin >> a >> b;
            if(fromTo[b].count(a)){
                remaining -= 2;
                fromTo[b].erase(fromTo[b].find(a));
            } else {
                fromTo[a].insert(b);
            }
        }
        cout << (remaining == 0 ? "YES" : "NO") << endl;
    }
}
