#include <bits/stdc++.h>

// idea:
// congruence relation
// if a%d == b%d, then (a-b)%d = 0
// thus d is a divisor than leave no remainder for (v2-v1)/d
// solution is thus to find the gcd of all (v1-v2), all pairs
// either gcd(v2-v1, v3-v2) or gcd(v3-v1,v3-v2) will work

using namespace std;

int gcd(int a, int b){
    return a==0 ? b : gcd(b%a, a);
}

int main()
{
    int first, val;
    while(scanf("%d",&first), first != 0){
        int res = 0;
        while(scanf("%d",&val), val != 0)
            res = gcd(res, val-first);
        printf("%d\n", abs(res));
    }
}
