#include <bits/stdc++.h>
using namespace std;

int n, highest;
string in, in2;
map<string,int> toIdx;
vector<vector<int>> graph;
int memo[201][2]; // state: employeeIdx, skip?
bool repeat[201][2];

int solve(int idx, int skip) {
    if(memo[idx][skip] != -1) return memo[idx][skip];

    int best = 0;
    bool not_distinct = false;
    // skip
    if(skip) {
        for(auto& next : graph[idx]){
            int a = solve(next, 1);
            int b = solve(next, 0);
            best += max(a,b);
            if(a==b) not_distinct = true;
            else if(a>b) not_distinct |= repeat[next][1];
            else not_distinct |= repeat[next][0];
        }
    } else {
        best = 1;
        for(auto& next : graph[idx]){
            best += solve(next, 1);
            not_distinct |= repeat[next][1];
        }
    }

    repeat[idx][skip] = not_distinct;
    return memo[idx][skip] = best;
}

int main() {
    while(scanf("%d",&n),n){
        highest = 1;
        cin >> in; // boss
        toIdx.clear(); graph.assign(n,vector<int>());
        toIdx[in] = 0;
        memset(memo, -1, sizeof memo);
        memset(repeat, 0, sizeof repeat);
        for(int i=1;i<n;i++) {
            cin >> in >> in2;
            if(!toIdx.count(in)) toIdx[in] = highest++;
            if(!toIdx.count(in2)) toIdx[in2] = highest++;
            graph[toIdx[in2]].push_back(toIdx[in]);
        }
        int best = solve(0,0);
        int best2 = solve(0,1);
        bool not_distinct;
        if(best == best2) not_distinct = true;
        else if(best > best2) {
            not_distinct = repeat[0][0];
        } else {
            not_distinct = repeat[0][1];
            best = best2;
        }
        printf("%d %s\n", best, not_distinct ? "No" : "Yes");
    }
}
