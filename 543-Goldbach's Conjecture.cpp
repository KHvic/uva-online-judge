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
        bool found = false;
        for(int i=0; i<primes.size() && !found; i++){
            int complement = in - primes[i];
            if(complement < 0) break;
            if(isPrime[complement]){
                printf("%d = %d + %d\n",in,primes[i],complement);
                found = true;
            }
        }
        if(!found)
            printf("‘Goldbach's conjecture is wrong.\n");
    }
}
