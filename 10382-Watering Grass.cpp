#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,l,w,p,r;
    while(scanf("%d %d %d",&n,&l,&w) != EOF){
        vector<pair<double,double>> intervals;
        for(int i=0;i<n;i++){
            scanf("%d %d",&p,&r);
            double dx = sqrt((double)r*r-(w/2.0)*(w/2.0));
            if(dx == dx){ // check for nan
                intervals.push_back({(double)p-dx,(double)p+dx});
            }
        }
        sort(intervals.begin(),intervals.end());
        double cur = 0;
        int res = 0;
        for(int i=0;i<intervals.size() && cur < l;i++){
            // not intersecting, impossible
            if(intervals[i].first > cur) {
                break;
            }
            res++;
            // find out furthest interval to right we can reach
            double furthest = intervals[i].second;
            while(i+1<intervals.size() && intervals[i+1].first <= cur){
                furthest = max(intervals[++i].second,furthest);
            }
            cur = furthest;
        }
        if(cur < l) res = -1;
        printf("%d\n",res);
    }
}
