#include <bits/stdc++.h>
using namespace std;

int memo[41][80001];
int n,f,t;
int trans[1001];
bool can_pos[41], can_neg[41];

bool solve(int idx, int val) {
    if(idx == n) {
        return val==f;
    }
    if(memo[idx][val+16000] != -1) return memo[idx][val+16000] == 1;
    // try subtract
    bool sub = false, add = false;
    if(val-trans[idx]+16000 >= 0)
        sub = solve(idx+1,val-trans[idx]);
    if(val+trans[idx]+16000 < 80001)
        add = solve(idx+1,val+trans[idx]);
    if(sub) can_neg[idx] = true;
    if(add) can_pos[idx] = true;

    return memo[idx][val+16000] = (sub || add) ? 1 : 0;
}

int main() {
    while(scanf("%d %d",&n,&f),(n+f)){
        memset(memo, -1, sizeof memo);
        memset(can_pos, false, sizeof can_pos);
        memset(can_neg, false, sizeof can_neg);
        for(int i=0;i<n;i++){
            scanf("%d",trans+i);
        }
        bool solvable = solve(0,0);
        if(!solvable) printf("*\n");
        else {
            for(int i=0;i<n;i++){
                if(can_neg[i] && can_pos[i])
                    printf("?");
                else if(can_neg[i])
                    printf("-");
                else printf("+");
            }
            printf("\n");
        }
    }
}
