#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void sieve(){
    primes.clear();
    bitset<1000001> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(long long i=2;i<1000001;i++){
        if(isPrime[i]) {
            primes.push_back(i);
            for(long long j=i*i;j<1000001;j+=i)
                isPrime[j] = false;
        }
    }
}

vector<int> primeFactors(long long n, vector<int>& factors) {
    long long PF_idx = 0, PF = primes[PF_idx];
    while(PF * PF <= n) {
        while(n % PF == 0) {
            n /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx]; // next prime
    }
    if (n != 1) factors.push_back(n); // remaining num is a prime
    return factors;
}

int main()
{
    sieve();
    int n;
    while(scanf("%d",&n),n!=0){
        vector<int> factors;
        if(n < 0) factors.push_back(-1);
        else if(n == 1) factors.push_back(1);
        primeFactors(abs(n), factors);
        printf("%d =",n);
        for(auto& factor : factors){
            printf(" %d", factor);
            if(&factor != &factors.back()) printf(" x");
        }
        printf("\n");
    }
}
