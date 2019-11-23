#include <bits/stdc++.h>

using namespace std;
#define N 1000001
#define ll long long
vector<int> numDiffPF;

// compute num of different PF each number have
void modifiedSieve(){
    numDiffPF.assign(N, 0);
    for(long long i=2;i<N;i++){
        if(numDiffPF[i] == 0) {
            for(long long j=i;j<N;j+=i)
                numDiffPF[j]++;
        }
    }
}

int main()
{
    modifiedSieve();
    int v;
    while(scanf("%d",&v),v){
        printf("%d : %d\n",v,numDiffPF[v]);
    }
}
