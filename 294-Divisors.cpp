#include <bits/stdc++.h>

using namespace std;
#define N 40000 // larger than sqrt of 1e9

vector<int> primes;

void sieve(){
    primes.clear();
    bitset<N> isPrime;
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

int numDivisor(int n) {
    int ans = 1; // itself
    // terminating condition, 1 or 0 prime factor left
    for(int idx=0;primes[idx]*primes[idx] <= n; idx++) {
        int exp = 0;
        while(n % primes[idx] == 0) {
            n /= primes[idx];
            exp++;
        }
        ans *= (exp+1);
    }
    if (n != 1) ans *= 2; // last factor has exp 1
    return ans;
}

int main()
{
    sieve();
    int tc, l, u;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d",&l,&u);
        int best = -1, bestDivisor = -1;
        for(int i=l;i<=u;i++) {
            int numDivs = numDivisor(i);
            if(numDivs > bestDivisor) {
                best = i;
                bestDivisor = numDivs;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, best, bestDivisor);
    }
}
