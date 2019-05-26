#include <bits/stdc++.h>
using namespace std;

int main() {
    int len,g,p,r;
    while(scanf("%d %d",&len,&g),len||g){
        vector<pair<int,int>> intervals;
        for(int i=0;i<g;i++){
            scanf("%d %d",&p,&r);
            intervals.push_back({p-r,p+r});
        }
        sort(intervals.begin(),intervals.end());
        int cur = 0;
        int res = 0;
        for(int i=0;i<g && cur<len;i++){
            if(intervals[i].first > cur) {
                break;
            }
            int furthestRight = intervals[i].second;
            while(i+1<intervals.size() && intervals[i+1].first <= cur){
                furthestRight = max(intervals[++i].second,furthestRight);
            }
            res++;
            cur = furthestRight;
        }
        if(cur<len){
            printf("-1\n");
        } else {
            printf("%d\n",g-res);
        }
    }
}
