#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,m,l,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        vector<pair<int,int>> intervals;
        while(scanf("%d %d",&l,&r),l||r){
            intervals.push_back({l,r});
        }
        sort(intervals.begin(),intervals.end());
        vector<int> res;
        int cur = 0;
        for(int i=0;i<intervals.size() && cur<m;i++){
            if(intervals[i].first > cur) {
                res.clear();
                break;
            }
            int furthestRight = intervals[i].second;
            int best = i;
            while(i+1<intervals.size() && intervals[i+1].first <= cur){
                if(furthestRight<intervals[++i].second){
                    furthestRight = intervals[i].second;
                    best = i;
                }
            }
            res.push_back(best);
            cur = furthestRight;
        }
        if(cur<m){
            printf("0\n");
        } else {
            printf("%d\n",res.size());
            for(auto& i : res)
                printf("%d %d\n",intervals[i].first,intervals[i].second);
        }
        if(t) cout << endl;
    }
}
