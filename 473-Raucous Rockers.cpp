#include <bits/stdc++.h>
using namespace std;

vector<int> songs;
int tc,n,t,m;
char c;
// state: diskIdx,remainingTime,diskLeft
vector<vector<vector<int>>> memo;

int solve(int idx, int time, int disk) {
    if(disk == 0 || idx == songs.size()) return 0;
    if(memo[idx][time][disk] != -1) return memo[idx][time][disk];
    int best = solve(idx+1, time, disk);
    best = max(best, solve(idx, t, disk-1));
    if(time >= songs[idx]) {
        best = max(best, solve(idx+1, time-songs[idx], disk) + 1);
    }
    return memo[idx][time][disk] = best;
}

int main() {
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d %d",&n,&t,&m);
        songs.assign(n,0);
        memo.assign(n,vector<vector<int>>(t+1,vector<int>(m+1,-1)));
        for(int i=0;i<n;i++) {
            scanf("%d%c",&songs[i],&c);
        }
        printf("%d\n", solve(0,t,m));
        if(tc) printf("\n");
    }
}
