#include <bits/stdc++.h>
using namespace std;

int f,l;
int memo[45][45];

int solve(int low, int high){
    if(low == high) return 1;
    else if(low > high) return 0;
    if(memo[low][high] != -1) return memo[low][high];
    int res = 0;
    for(int m=low+1;m<=high;m++){
        int diff = m-low;
        // longer method if a1 = low, a2 = m, can we form a1 using the diff?
//        int times = ceil((double)low/diff);
//        if(times*diff == low){
//            res += solve(m,high);
//        }
        // actually just need to check for divisibility, definitely can form a1
        if((low%diff) == 0)
            res += solve(m, high);
    }
    return memo[low][high] = res;
}

int main() {
    while(scanf("%d %d",&f,&l), f<l) {
        memset(memo, -1, sizeof memo);
        printf("%d %d %d\n", f, l, solve(f, l));
    }
}
