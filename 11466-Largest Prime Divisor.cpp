#include <bits/stdc++.h>

using namespace std;

const int n = 10000001; // within sqrt of 1e14
vector<int> primes;
bitset<n> isPrime;

void sieve(){
    primes.clear();
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(long long i=2;i<n;i++)
    if(isPrime[i]) {
        primes.push_back(i);
        for(long long j=i*i;j<n;j+=i){
            isPrime[j] = false;
        }
    }
}

int main() {
    sieve();
    long long v;
    while(scanf("%lld",&v),v){
        v = abs(v);
        if(v <= n && isPrime[v]) printf("-1\n");
        else {
            long long largest = 0;
            int cnt = 0;
            long long cur = v;
            for(int i=0;i<primes.size() && primes[i]<=sqrt(v);i++) {
                if(cur % primes[i] == 0){
                    cnt++;
                    largest = primes[i];
                    while(cur % primes[i] == 0) {
                        cur /= primes[i];
                    }
                }
            }
            if(cur != 1) {
                // then remainder is the divisor
                largest = cur;
                cnt++;
            }
            if(cnt > 1) printf("%lld\n",largest);
            else printf("-1\n");
        }
    }
}
