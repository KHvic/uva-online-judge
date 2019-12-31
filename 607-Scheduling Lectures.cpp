#include <bits/stdc++.h>
using namespace std;

int n,l,c,v;
vector<int> topics;
// state: idx = {num lecture, DI}
vector<pair<int,int>> memo;

pair<int,int> solve(int idx) {
    if(idx == n) return {0,0};
    if(memo[idx].first != -1) return memo[idx];
    int min_lec = INT_MAX;
    int min_DI = INT_MAX;
    int time_left = l;
    for(int i=idx;i<n;i++){
        time_left -= topics[i];
        if(time_left < 0) break;
        int di = 0;
        if(time_left==0) di = 0;
        else if(time_left<=10) di = -c;
        else di = (time_left-10)*(time_left-10);

        pair<int,int> sub_res = solve(i+1);
        int lec_needed = sub_res.first+1;
        di += sub_res.second;
        if(lec_needed < min_lec) {
            min_lec = lec_needed;
            min_DI = di;
        } else if(min_lec == lec_needed) {
            min_DI = min(min_DI, di);
        }
    }
    return memo[idx] = {min_lec, min_DI};
}

int main() {
    int tc=1;
    while(scanf("%d",&n),n){
        if(tc>1) printf("\n");
        scanf("%d %d",&l,&c);
        memo.assign(n,{-1,-1});
        topics.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            topics.push_back(v);
        }
        pair<int,int> res = solve(0);
        printf("Case %d:\n",tc++);
        printf("Minimum number of lectures: %d\n", res.first);
        printf("Total dissatisfaction index: %d\n", res.second);
    }
}
