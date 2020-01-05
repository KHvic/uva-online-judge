#include <bits/stdc++.h>
using namespace std;

// key idea: third chopstick doesn't really matter, can use any longer stick
vector<int> sticks;
int memo[1011][5001]; // states: remaining people, chopstick index

int solve(int rem_k, int idx){
    if(rem_k == 0) return 0;
    int sticks_left = (sticks.size() - idx);
    if(sticks_left < rem_k*3) return 1e7; // not enough for everyone
    if(memo[rem_k][idx] != -1) return memo[rem_k][idx];

    // do not use chopsticks
    int best = solve(rem_k, idx+1);
    // use chopsticks
    int badness = (sticks[idx+1]-sticks[idx]);
    badness *= badness;
    best = min(best, solve(rem_k-1,idx+2) + badness);

    return memo[rem_k][idx] = best;
}

int main() {
    int t,k,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&k,&n);
        k += 8;
        sticks.assign(n,0);
        memset(memo, -1, sizeof memo);
        for(int i=0;i<n;i++){
            scanf("%d",&sticks[i]);
        }
        printf("%d\n",solve(k,0));
    }
}
