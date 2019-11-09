#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
const int N = 50000;

void sieve(){
    bitset<N> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(long long i=2;i<N;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=i*i;j<N;j+=i)
                isPrime[j] = false;
        }
    }
}

// exponent of a prime p in n!
int get_powers(int n, int p) {
    int res = 0;
    for(int power=p; power<=n; power*=p)
        res += n/power;
    return res;
}

bool canDivide(int n, int m){
    for(int pidx = 0; pidx <primes.size()
    && primes[pidx]*primes[pidx] <= m; pidx++){
        int cntFactor = 0;
        while(m%primes[pidx] == 0) {
            cntFactor++;
            m /= primes[pidx];
        }
        int cntFactorN = get_powers(n, primes[pidx]);
        if(cntFactorN < cntFactor) return false;
    }
    // not fully factored and m is larger
    if(m != 1 && m > n) return false;
    return true;
}

int main() {
    sieve();
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF){
        if(canDivide(n, m))
            printf("%d divides %d!\n", m, n);
        else
            printf("%d does not divide %d!\n", m, n);
    }
}
