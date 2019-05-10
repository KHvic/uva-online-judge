#include <bits/stdc++.h>

using namespace std;

// O(N) dynamic programming
// track largest negative number and cumulative product

int main()
{
    int n,v;
    int cases = 1;
    while(scanf("%d",&n) != EOF){
        long long largestNeg = 0;
        long long dpProd = 1;
        long long res = 0;
        for(int i=0;i<n;i++){
            cin >> v;
            dpProd *= v;
            if(dpProd == 0){
                largestNeg = 0;
                dpProd = 1;
            } else if(dpProd > 0){
                res = max(res,dpProd);
            } else {
                if(largestNeg) res = max(res,dpProd/largestNeg);
                else largestNeg = dpProd;
                largestNeg = max(largestNeg,dpProd);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",cases++,res);
    }
}
