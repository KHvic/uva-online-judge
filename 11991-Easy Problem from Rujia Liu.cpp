#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k,v;
    while(scanf("%d %d\n",&n,&m) != EOF){
        unordered_map<int,vector<int>> posMap;
        for(int i=1;i<=n;i++){
            cin >> v;
            posMap[v].push_back(i);
        }
        for(int i=0;i<m;i++){
            cin >> k >> v;
            k--;
            vector<int>& posVec = posMap[v];
            if(k>=posVec.size()) cout << 0 << endl;
            else cout << posVec[k] << endl;
        }
    }
}
