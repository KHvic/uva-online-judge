#include <bits/stdc++.h>
using namespace std;
// O(nlogn) using multimap and sort
int main() {
    int l,h,r;
    vector<pair<int,int>> buildings;
    while(scanf("%d %d %d", &l, &h, &r) != EOF){
        buildings.push_back({l,h});
        buildings.push_back({r,-h}); // negative to indicate end pos
    }
    sort(buildings.begin(),buildings.end(),[](pair<int,int>& a, pair<int,int>& b){
            // sort by x pos
            if(a.first != b.first) return a.first < b.first;
            // both are start points, evaluate higher first
            else if(a.second > 0 && b.second > 0)
                return a.second > b.second;
            // both are end points, evaluate lower first
            else if(a.second < 0 && b.second < 0)
                return a.second > b.second;
            return a.second > 0; // start first then end
         }
    );

    multiset<int> height;
    height.insert(0);
    int maxHeight = 0;
    bool notfirst = false;
    for(auto& p : buildings){
        if(p.second < 0){
            height.erase(height.find(abs(p.second)));
        } else {
            height.insert(p.second);
        }
        int curMax = *prev(height.end());
        if(curMax != maxHeight){
            // there is a change of height
            if(notfirst) cout << " ";
            notfirst = true;
            cout << p.first << " " << curMax;
            maxHeight = curMax;
        }
    }
    cout << endl;
}
