#include <bits/stdc++.h>
using namespace std;
#define lim 1000000

vector<int> primes;
vector<int> N;

void sieve(){
    bitset<1000001> isPrime;
    isPrime.set();
    for(long long i=2;i<=1000000;i++)
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=i*i;j<=1000000;j+=i)
                isPrime[j] = false;
        }
}

// a number can be represented as product of primes:
// N = prime1^a * prime2^b ...
// num divisor = (a+1)*(b+1)*(c+1)...
int numDivisor(int n){
    int res = 1;
    for(int i=0;i<primes.size() && primes[i]<=n;i++){
        int count = 0;
        // if divisible by prime
        while(n%primes[i]==0){
            n /= primes[i];
            count++;
        }
        res = res*(count+1);
    }
    return res;
}

void build(){
    N.push_back(1);
    while(N.back()<=lim){
        N.push_back(N.back()+numDivisor(N.back()));
    }
}

int main() {
    sieve();
    build();
    int t,a,b,tc=1;
    cin >> t;
    while(t--){
        cin >> a >> b;
        auto lower = lower_bound(N.begin(),N.end(),a);
        auto higher = upper_bound(lower,N.end(),b);
        printf("Case %d: %d\n",tc++,higher-lower);
    }
}
