#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    int s,v;
    while(scanf("%d %d",&m,&n) != EOF){
        vector<vector<pair<int,int>>> transpose(n,vector<pair<int,int>>());
        for(int i=0;i<m;i++){
            cin >> s;
            vector<int> pos;
            for(int j=0;j<s;j++){
                cin >> v;
                pos.push_back(v-1);
            }
            for(int j=0;j<s;j++){
                cin >> v;
                transpose[pos[j]].push_back({v,i+1});
            }
        }
        printf("%d %d\n",n,m);
        for(int i=0;i<n;i++){
            cout << transpose[i].size();
            for(auto& p : transpose[i]) cout << " " << p.second;
            cout << endl;
            for(auto& p : transpose[i])
                cout << p.first << (&p == &transpose[i].back() ? "" : " ");
            cout << endl;
        }
    }
}
