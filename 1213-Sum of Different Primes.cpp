#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<vector<int>> dp(1121,vector<int>(15));

void sieve(){
    bitset<1121> bs;
    bs.set();
    for(int i=2;i<1121;i++)
    if(bs[i]){
        primes.push_back(i);
        for(int j=i*i;j<1121;j+=i) bs[j] = false;
    }
}

void knapsack(){
    dp[0][0] = 1;
    for(auto& prime : primes){
        for(int i=1120;i>=prime;i--)
            for(int j=1;j<15;j++)
                dp[i][j] += dp[i-prime][j-1];
    }
}

int main()
{
    sieve();
    knapsack();
    int n,k;
    while(scanf("%d %d",&n,&k),n||k){
        printf("%d\n",dp[n][k]);
    }
}
