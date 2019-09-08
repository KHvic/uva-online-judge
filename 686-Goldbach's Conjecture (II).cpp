#include <bits/stdc++.h>

using namespace std;
vector<int> primes;
bitset<1000001> isPrime;
void sieve()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(long long i=2; i<1000001; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=i*i; j<1000001; j+=i)
                isPrime[j] = 0;
        }
    }
}

int main()
{
    sieve();
    int in;
    while(scanf("%d",&in), in != 0){
        int res = 0;
        for(int i=0; i<primes.size(); i++){
            int complement = in - primes[i];
            if(complement < 0 || complement < primes[i]) break;
            if(isPrime[complement]){
                res++;
            }
        }
        printf("%d\n",res);
    }
}
