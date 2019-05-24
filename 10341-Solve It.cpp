#include <bits/stdc++.h>
using namespace std;

int p,q,r,s,t,u;

double f(double mid){
    return p*exp(-mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*mid*mid+u;
}

int main() {
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) != EOF){
// Given f(x) = 0:
// Since f is a non-increasing function on [0,1],
// it is sufficient to check the signs for f(0) and f(1) to determine whether
// there is a root in range [0,1]. 
        if(f(0)*f(1) > 0) printf("No solution\n");
        else {
            double lo = 0, hi = 1;
            while((hi-lo) > 0.0000001){
                double mid = (lo+hi)/2;
                double val = f(mid);
                // raising x, decreases our val
                if(val > 0) lo = mid;
                else hi = mid;
            }
            printf("%.4f\n",lo);
        }
    }
}
