#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    int a,b,c;
    while(scanf("%d %d",&n,&m),n||m){
        int res = 0;
        vector<int> ppl = {0,1,2,3,4,5,6,7};
        vector<int> seat = {0,1,2,3,4,5,6,7};
        vector<tuple<int,int,int>> constraints;
        for(int i=0;i<m;i++){
            cin >> a >> b >> c;
            constraints.push_back(make_tuple(a,b,c));
        }
        do{
            for(int i=0;i<n;i++) seat[ppl[i]] = i;
            bool satisfy = true;
            // check each constraint
            for(int i=0;i<constraints.size() && satisfy;i++){
                auto& tup = constraints[i];
                int p1 = get<0>(tup), p2 = get<1>(tup), req = get<2>(tup);
                int dist = abs(seat[p1] - seat[p2]);
                if(req < 0){
                    // must be req length apart
                    satisfy = dist >= abs(req);
                } else {
                    // must be within req
                    satisfy = dist <= req;
                }
            }
            if(satisfy) res++;
        }while(next_permutation(ppl.begin(),ppl.begin()+n));
        cout << res << endl;
    }
}
