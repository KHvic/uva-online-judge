#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double day;
    while(scanf("%d",&n),n){
        int best_can = 100000, best_us = 0;
        // greedy + dp
        // each day we try to convert from all from one currency to another, track the max
        for(int i=0;i<n;i++){
            scanf("%lf",&day);
            // 1us = day can
            // 1can = 1/day us
            int us = best_can / day * 0.97;
            int canada = best_us * day * 0.97;
            best_can = max(best_can, canada);
            best_us = max(best_us, us);
        }
        printf("%d.%02d\n",best_can/100,best_can%100);
    }
}
