#include <bits/stdc++.h>

using namespace std;
#define N 1000001
#define ll long long
vector<int> numDiffPF;
vector<int> mu;
vector<int> mertens;

void modifiedSieve(){
    numDiffPF.assign(N, 0);
    mu.assign(N, 1);
    mertens.assign(N, 0);
    mertens[1] = 1;
    for(long long i=2;i<N;i++){
        if(numDiffPF[i] == 0) {
            long long sq = i*i;
            for(long long j=i;j<N;j+=i){
                numDiffPF[j]++;
                if(j%sq == 0) mu[j] = 0; // not square free
            }
        }
        if(mu[i] && numDiffPF[i]%2 == 1) {
            mu[i] = -1;
        }
        mertens[i] = mertens[i-1] + mu[i];
    }
}

int main()
{
    modifiedSieve();
    int v;
    while(scanf("%d",&v),v){
        printf("%8d%8d%8d\n",v,mu[v],mertens[v]);
    }
}
