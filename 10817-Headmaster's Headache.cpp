#include <bits/stdc++.h>
using namespace std;

int s,m,n,c,t,ok;
string in;
vector<pair<int,int>> applicants;
int memo[1<<16][101];

int add_teacher(int cur, int bitmask) {
    int exist = cur & bitmask; // already have subjects
    cur |= bitmask;
    cur |= (exist << 8);
    return cur;
}

int solve(int bitmask, int idx) {
    if(bitmask == ok) return 0 ;
    else if(idx>=n) return 1e7;
    else if(memo[bitmask][idx] != -1) return memo[bitmask][idx];

    // exclude
    int best = solve(bitmask, idx+1);
    // include
    best = min(best, solve(add_teacher(bitmask, applicants[idx].second), idx+1) + applicants[idx].first);

    return memo[bitmask][idx] = best;
}

int main() {
    while(scanf("%d %d %d\n",&s,&m,&n), (s+m+n)){
        applicants.clear();
        memset(memo, -1, sizeof memo);
        int cost = 0;
        int bitmask = 0;
        ok = (1<<s)-1;
        ok |= (ok<< 8);
        for(int i=0;i<m;i++){
            getline(cin,in);
            istringstream iss(in);
            iss >> c;
            cost += c;
            int subjects = 0;
            while(iss >> t) {
                t--;
                subjects |= (1<<t);
            }
            bitmask = add_teacher(bitmask, subjects);
        }
        for(int i=0;i<n;i++){
            getline(cin,in);
            istringstream iss(in);
            iss >> c;
            int subjects = 0;
            while(iss >> t) {
                t--;
                subjects |= (1<<t);
            }
            applicants.push_back({c,subjects});
        }
        printf("%d\n", solve(bitmask, 0)+cost);
    }
}
