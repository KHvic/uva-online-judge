#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<vector<ll>> memo(25, vector<ll>(151,-1));

ll solve(int n, int x) {
    if(n == 0)
        return x == 0 ? 1 : 0;
    if(memo[n][x] != -1) return memo[n][x];
    ll res = 0;
    for(int i=1;i<=6;i++) {
        // can't go below 0, already meet requirement
        int nextX = max(x - i, 0);
        res += solve(n-1, nextX);
    }
    memo[n][x] = res;
    return res;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main()
{
    int n,x;
    while(scanf("%d %d",&n,&x),(n+x)) {
        ll numerator = solve(n,x);
        ll denominator = floor(pow(6, n));
        if(numerator == denominator) {
            printf("1\n");
        } else if(numerator != 0) {
            ll d = gcd(numerator, denominator);
            numerator /= d;
            denominator /= d;
            printf("%lld/%lld\n", numerator, denominator);
        } else {
            printf("0\n");
        }
    }
}
