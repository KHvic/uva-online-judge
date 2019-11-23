#include <bits/stdc++.h>

using namespace std;
#define N 101
#define ll long long
vector<int> primes;
bitset<N> isPrime;

void sieve(){
    primes.clear();
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(long long i=2;i<N;i++){
        if(isPrime[i]) {
            primes.push_back(i);
            for(long long j=i*i;j<N;j+=i)
                isPrime[j] = false;
        }
    }
}

// sum of all divisors of n
// mul((PF^(pow+1) -1) / (PF-1)) for all PF
// each sum if the sum of a geometric series
int sumDivisors(int n) {
    int ans = 1;
    for(int idx=0;primes[idx]*primes[idx] <= n; idx++) {
        int exp = 0;
        while(n % primes[idx] == 0) {
            n /= primes[idx];
            exp++;
        }
        // use ceil because pow returns a floating power that could be inaccurate
        ans *= (ceil(pow(primes[idx], exp+1)) -1) / (primes[idx]-1);
    }
    if (n != 1)
        ans *= (ceil(pow(n, 2)) -1) / (n-1);
    return ans;
}

int main()
{
    sieve();
    int tc=1, v;
    vector<int> ans(1001,-1);
    for(int i=1;i<1001;i++) {
        int sum = sumDivisors(i);
        if(sum<1001) ans[sum] = i;
    }
    while(scanf("%d",&v),v){
        printf("Case %d: %d\n", tc++, ans[v]);
    }
}
