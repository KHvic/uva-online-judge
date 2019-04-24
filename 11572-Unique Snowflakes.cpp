#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, v;
    scanf("%d",&t);
    while(t--){
        cin >> n;
        unordered_map<int,int> lastSeen;
        int lastIdxWithoutDup = 0;
        int longest = 0, res = 0;
        for(int i=1;i<=n;i++){
            cin >> v;
            int last = lastSeen[v];
            lastIdxWithoutDup = max(last,lastIdxWithoutDup);
            res = max(i-lastIdxWithoutDup, res);
            lastSeen[v] = i;
        }
        cout << res << endl;
    }
}
