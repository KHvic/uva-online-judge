#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,time,fine;
    cin >> t;
    while(t--){
        cin >> n;
        vector<tuple<int,int,int>> jobs;
        for(int i=0;i<n;i++){
            cin >> time >> fine;
            jobs.push_back(make_tuple(time,fine,i+1));
        }
        // greedy problem has sub-optimal solution
        // consider comparing two events, with all the other events being fixed
        // we compare them which gives us the less fine
        // if we choose to complete a first, the fine will be a.time*b.fine
        // if we choose to complete b first, the fine will be b.time*a.fine
        auto cmp = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b){
            return (get<0>(a)*get<1>(b)) < (get<0>(b)*get<1>(a));
        };
        stable_sort(jobs.begin(),jobs.end(),cmp);
        for(auto& t : jobs){
            cout << get<2>(t);
            if(&t == &jobs.back()) cout << endl;
            else cout << " ";
        }
        if(t) cout << endl;
    }
}
