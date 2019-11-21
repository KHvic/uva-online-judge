#include <bits/stdc++.h>
using namespace std;
#define N 10001

vector<int> primes;

void sieve() {
    bitset<N> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    vector<int> basePrime(N,1);

    for(long long i=2;i<N;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=i*i;j<N;j+=i)
                isPrime[j] = false;
        }
    }
}


int main() {
    sieve();
    int tc;
    int a,c;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&a,&c);
        if(c%a == 0) {
            int b = 1;
            // prime factorization
            // primes[i]*primes[i] condition, can just take c as remaining factor if it is larger than primes[i]^2
            for(int i=0; i<primes.size() && primes[i]*primes[i]<=c; i++) {
                int factorCntA=0, factorCntC=0;
                int totalFactor = 1;
                while(a%primes[i] == 0) {
                    factorCntA++;
                    a/=primes[i];
                }
                while(c%primes[i] == 0) {
                    factorCntC++;
                    c/=primes[i];
                    totalFactor *= primes[i];
                }
                if(factorCntC > factorCntA)
                    b *= totalFactor;
            }
            if(c > 1 && a == 1) b *= c;
            printf("%d\n", b);
        } else {
            printf("NO SOLUTION\n");
        }
    }
}
