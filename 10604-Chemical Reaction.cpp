#include <bits/stdc++.h>
using namespace std;

map<vector<int>, int> memo;
int tc,m,p,h,k,v;
char c;

vector<vector<pair<int,int>>> combine;

int solve(vector<int> state) {
    if(memo.count(state)) return memo[state];
    int best = 1e7;
    int remaining = 0;
    for(int i=0;i<m;i++){
        remaining += state[i];
        if(state[i] > 0) {
            state[i]-=1;
            for(int j=0;j<m;j++){
                if(state[j] > 0) {
                    state[j]-=1;
                    state[combine[i][j].first]+=1;
                    best = min(best, combine[i][j].second+solve(state));
                    state[combine[i][j].first]-=1;
                    state[j]+=1;
                }
            }
            state[i]+=1;
        }
    }
    if(remaining == 1) best = 0;
    return memo[state] = best;
}

int main() {
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&m);
        combine.clear();
        memo.clear();
        for(int i=0;i<m;i++){
            vector<pair<int,int>> row;
            for(int j=0;j<m;j++){
                scanf("%d %d",&p,&h);
                p--;
                row.push_back({p,h});
            }
            combine.push_back(row);
        }
        vector<int> cnt(m+1,0);
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d",&v);
            v--;
            cnt[v]++;
        }
        printf("%d\n",solve(cnt));
        cin >> c;
    }
}
