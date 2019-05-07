#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,v;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> neigh;
        int sum = 0;
        while(n--){
            cin >> v;
            neigh.push_back(v);
        }
        sort(neigh.begin(),neigh.end());
        int median = neigh[neigh.size()/2];

        for(auto& v : neigh) sum += abs(v-median);

        cout << sum << endl;
    }
}
