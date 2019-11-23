#include <bits/stdc++.h>

using namespace std;

int solve(int b, int p, int m) {
    if (p==0) return 1;

    int half = solve(b,p/2,m)%m;
    int res = (half*half)%m;
    if(p%2==1)
        return (res*b)%m;
    return res;
}

int main()
{
    // compute b^p mod m
    int b,p,m;
    while(scanf("%d",&b) != EOF) {
        scanf("%d %d",&p,&m);
        b%=m;
        printf("%d\n",solve(b,p,m)%m);
    }
}
