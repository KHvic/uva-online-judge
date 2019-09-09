#include <bits/stdc++.h>

using namespace std;

vector<int> twinPrimes;
bitset<20000001> isPrime;
void sieve(){
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(long long i=2;i<20000001;i++){
        if(isPrime[i]){
            for(long long j=i*i;j<20000001;j+=i){
                isPrime[j] = false;
            }
            if(isPrime[i-2])
                twinPrimes.push_back(i);
        }
    }
}

int main() {
    sieve();
    int n;
    while(scanf("%d",&n) != EOF){
        printf("(%d, %d)\n",twinPrimes[n-1]-2,twinPrimes[n-1]);
    }
}
