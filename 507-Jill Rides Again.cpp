#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b,r,v,tc=1;
    cin >> b;
    while(b--){
        cin >> r;
        int bestFrom = 0, bestTo = 0, best = 0;
        int curFrom = 0, cur = 0;
        for(int i=1;i<r;i++){
            cin >> v;
            cur += v;
            // reset cur if fall below 0
            if(cur<0){
                curFrom = i;
                cur = 0;
            }
            // update best if higher or have larger index distance
            if(cur>best || (cur == best && (i-curFrom) > (bestTo-bestFrom))){
                bestFrom = curFrom;
                bestTo = i;
                best = cur;
            }
        }
        if(best == 0) printf("Route %d has no nice parts\n",tc++);
        else
            printf("The nicest part of route %d is between stops %d and %d\n",tc++,bestFrom+1,bestTo+1);
    }
}
