#include <bits/stdc++.h>

using namespace std;
vector<int> sieve(int n){
    bitset<1000001> isPrime;
    isPrime.set();
    vector<int> res;
    for(long long i=2;i<=n;i++)
    if(isPrime[i]){
        res.push_back(i);
        for(long long j=i*i;j<=n;j+=i) isPrime[j] = false;
    }
    return res;
}

int main()
{
    vector<int> primes = sieve(1000000);
    int n, tc=1;
    while(cin >> n, n){
        int lo = 0;
        int hi = lower_bound(primes.begin(),primes.end(),n) - primes.begin();
        // two pointer
        int res = 0;
        while(lo<hi){
            long long total = primes[lo]+primes[hi];
            if(total <= n){
                res += (hi-lo);
                lo++;
            } else {
                hi--;
            }
        }
        printf("Case %d: %d\n",tc++,res);
    }
}
