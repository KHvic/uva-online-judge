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

// Eulter's Phi (Totient) function
// number of positive integers coprime to n, gcd(x,n) = 1
// basic idea of euler's phi is to remove fraction that is a factor of the prime
// N * mul(1-1/PF) for all PF
int eulerPhi(int n) {
    int ans = n; // itself
    for(int idx=0;primes[idx]*primes[idx] <= n; idx++) {
        if (n % primes[idx] == 0) ans -= ans/primes[idx];
        while(n % primes[idx] == 0) {
            n /= primes[idx];
        }
    }
    if (n != 1) ans -= ans/n;
    return ans;
}

int main()
{
    sieve();
    int n;
    while(scanf("%d",&n),n) {
        printf("%d\n", eulerPhi(n));
    }
}
