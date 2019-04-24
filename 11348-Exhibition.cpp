#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, p, n, v;
    int cases = 1;
    scanf("%d",&t);
    while(t--){
        cin >> p;
        unordered_map<int,unordered_set<int>> stampOwner;
        vector<double> res(p,0);
        for(int i=0;i<p;i++){
            cin >> n;
            while(n--){
                cin >> v;
                if(!stampOwner.count(v)) stampOwner[v] = unordered_set<int>();
                stampOwner[v].insert(i);
            }
        }
        int totalUnique = 0;
        for(auto& p : stampOwner){
            if(p.second.size() == 1) {
                totalUnique++;
                res[*p.second.begin()]++;
            }
        }
        cout << "Case " << cases++ << ":";
        for(auto& d : res)
            cout << " " << setprecision(6) << fixed << d*100.0/totalUnique << "%";
        cout << endl;
    }
}
