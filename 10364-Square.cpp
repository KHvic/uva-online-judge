#include <bits/stdc++.h>
using namespace std;

int tc,v,n,sum,ok;
vector<int> sticks;
vector<bool> visited;

// len doesn't have to be memoized as sum of bitmask is always the same
// bitmask is good enough to be the state
bool solve(int len, int bitmask) {
    if(bitmask == ok) return len == 0;
    else if(visited[bitmask]) return false;
    else if(len == sum/4) return solve(0,bitmask);
    else if(len > sum/4) return false;
    visited[bitmask] = true;

    for(int i=0;i<n;i++)
    if((bitmask & (1<<i))==0){
        if(solve(len+sticks[i],bitmask | (1<<i)))
            return true;
    }
    return false;
}

int main() {
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        sticks.clear();
        visited.assign(1<<n,false);
        sum = 0;
        ok = (1<<n)-1;
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            sticks.push_back(v);
            sum += v;
        }
        if(sum%4 == 0 && solve(0,0))
            printf("yes\n");
        else
            printf("no\n");
    }
}
