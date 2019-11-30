#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, a, b;

ll f(ll x) {
    return (a*(x*x%n)+b)%n;
}

pair<ll,ll> floydCycleFinding(ll x) {
    ll tortoise = f(x), hare = f(f(x));
    while(tortoise != hare) {
        tortoise = f(tortoise), hare = f(f(hare));
    }
    ll mu=0; hare=x;
    while(tortoise != hare) {
        tortoise = f(tortoise), hare = f(hare);
        mu++;
    }
    ll lambda = 1; hare = f(tortoise);
    while(tortoise != hare) {
        hare = f(hare);
        lambda++;
    }
    return make_pair(mu, lambda);
}


int main()
{
    while(scanf("%lld",&n),n){
        scanf("%lld %lld",&a,&b);
        pair<ll,ll> res = floydCycleFinding(0);
        printf("%lld\n",n-res.second);
    }
}
