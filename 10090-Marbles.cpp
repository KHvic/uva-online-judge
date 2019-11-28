#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll x, y, d;
void extendedEuclid(ll a, ll b) {
    if(b==0) { x=1; y=0; d=a; return;}
    extendedEuclid(b, a%b);
    ll y1 = x-(a/b)*y;
    x = y;
    y = y1;
}

int main() {
    ll v,n1,n2,c1,c2;
    while(scanf("%lld",&v),v){
        scanf("%lld %lld %lld %lld",&c1,&n1,&c2,&n2);
        extendedEuclid(n1,n2);
        if (v%d != 0) {
            printf("failed\n");
        } else {
            // to get to ax + by = v
            x *= v/d;
            y *= v/d;
            // two equations of Linear Diophantine
            /* x = x0 + (b/d)n, y = y0 − (a/d)n, where n is an integer */

            // derivation of n based on the fact that x and y has to be positive
            // x0 + (b/d)n >= 0, solve for n: we get n >= -x0*d/b
            // y0 - (a/d)n >= 0, solve for n: we get n <= y0*a/b
            // putting together x0*d/b <= n <= y0*d/b
            n2 /= d, n1 /= d; // divide first to prevent overflow
            ll lowerbound=ceil(-(double)x/n2);
            ll upperbound=floor((double)y/n1);
            if(lowerbound<=upperbound) {
                // compare cost
                ll res1 = c1*(x+n2*lowerbound) + c2*(y-n1*lowerbound);
                ll res2 = c1*(x+n2*upperbound) + c2*(y-n1*upperbound);
                if (res1 < res2) {
                    printf("%lld %lld\n",(x+n2*lowerbound), (y-n1*lowerbound));
                } else {
                    printf("%lld %lld\n",(x+n2*upperbound), (y-n1*upperbound));
                }
            } else
                printf("failed\n");
        }
    }
}
