#include <bits/stdc++.h>
using namespace std;

int a,b,t;
int memo[10001]; // max burger
int timeLeft[10001]; // min time left

// return pair<burger,time>
pair<int,int> solve(int rem){
    if(rem < 0) return {-1e7,1e7};
    else if(rem < min(a,b)) return {0,rem};
    else if(memo[rem] != -1) return {memo[rem],timeLeft[rem]};

    pair<int,int> eatA = solve(rem-a); eatA.first += 1;
    pair<int,int> eatB = solve(rem-b); eatB.first += 1;

    // choose least remaining time
    if(eatA.second == eatB.second) {
        memo[rem] = eatA.first > eatB.first ? eatA.first : eatB.first;
        timeLeft[rem] = eatA.first > eatB.first ? eatA.second : eatB.second;
    } else {
    // same time, choose higher burger
        memo[rem] = eatA.second < eatB.second ? eatA.first : eatB.first;
        timeLeft[rem] = eatA.second < eatB.second ? eatA.second : eatB.second;
    }
    return {memo[rem],timeLeft[rem]};
}

int main()
{
    while(scanf("%d %d %d",&a,&b,&t) != EOF){
        for(int i=0;i<=t;i++){
            memo[i] = -1;
            timeLeft[i] = 1e7;
        }
        pair<int,int> res = solve(t);
        if(res.second == 0) printf("%d\n",res.first);
        else printf("%d %d\n",res.first,res.second);
    }
}
