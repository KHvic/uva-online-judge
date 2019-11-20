#include <bits/stdc++.h>
using namespace std;
#define N 1000001


int main() {
    bitset<N> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    vector<int> basePrime(N,1);

    // sieve
    for(long long i=2;i<N;i++){
        if(isPrime[i]){
            for(long long j=i*i;j<N;j+=i)
                isPrime[j] = false;
            for(long long j=i;j<N;j*=i)
                basePrime[j] = i; // j = i^x, so has base prime of i
        }
    }

    // dp to compute lcm of 1...n
    vector<long long> dp(N);
    dp[1] = 1;
    for(int i=2;i<N;i++)
        dp[i] = (dp[i-1]*basePrime[i])%1000000000;

    int v;
    while (scanf("%d",&v), v) {
        long long res = dp[v];
        // filter zeros
        while (res % 10 == 0)res /= 10;
        // first non-zero
        res = res%10;
        printf("%lld\n",res);
    }
}
