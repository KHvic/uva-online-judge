#include <bits/stdc++.h>
using namespace std;

int t,n,v;
vector<vector<int>> time_taken;
int memo[281][1<<12][3]; // time_left, solved bitmask, previous solver

int solve(int time_left, int bitmask, int prev){
    if(time_left <= 0) return 0;
    if(prev != -1 && memo[time_left][bitmask][prev] != -1)
        return memo[time_left][bitmask][prev];
    int best = 0;
    for(int i=0;i<n;i++){
        if(!(bitmask & (1<<i))){
            // not solved, try solve
            for(int j=0;j<3;j++) {
                if(j == prev || time_taken[j][i]>time_left) continue; // no consecutive allowed
                int sub_res = solve(time_left-time_taken[j][i], bitmask^(1<<i), j)+1;
                best = max(best, sub_res);
            }
        }
    }
    if(prev != -1) memo[time_left][bitmask][prev] = best;
    return best;
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        time_taken.clear();
        memset(memo, -1, sizeof memo);
        for(int i=0;i<3;i++){
            vector<int> vec;
            for(int j=0;j<n;j++){
                scanf("%d",&v);
                vec.push_back(v);
            }
            time_taken.push_back(vec);
        }
        printf("%d\n",solve(280,0,-1));
    }
}
