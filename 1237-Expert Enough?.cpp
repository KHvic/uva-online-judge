#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,l,r,p;
    string n;
    cin >> t;
    while(t--){
        vector<tuple<string,int,int>> vec;
        cin >> p;
        for(int i=0;i<p;i++){
            cin >> n >> l >> r;
            vec.push_back(make_tuple(n,l,r));
        }
        cin >> l;
        while(l--){
            cin >> p;
            int cnt = 0;
            string name;
            for(int i=0;i<vec.size() && cnt<2;i++)
                if(get<1>(vec[i]) <= p && get<2>(vec[i]) >= p){
                    cnt++;
                    name = get<0>(vec[i]);
                }
            cout << (cnt == 1 ? name : "UNDETERMINED") << endl;
        }
        if(t) cout << endl;
    }
}
