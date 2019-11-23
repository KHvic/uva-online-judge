#include <bits/stdc++.h>

using namespace std;
#define N 2000001
vector<int> eulerPhi;
vector<int> depthPhi;
vector<int> sumDepth;

// eulerphi(x) = x * (1-1/PF) for all PF of x
void modifiedSieve(){
    eulerPhi.assign(N, 0);
    for(int i=0; i<N; i++) eulerPhi[i] = i;
    depthPhi.assign(N, 0);
    sumDepth.assign(N, 0);
    for(long long i=2;i<N;i++){
        // eulerphi(i) = i-1 if i is a prime number
        // thus, prime number can be checked using eulerphi
        if(eulerPhi[i] == i) {
            for(long long j=i;j<N;j+=i){
                eulerPhi[j] -= eulerPhi[j]/i; // remove fraction
            }
        }
        depthPhi[i] = depthPhi[eulerPhi[i]] + 1;
        sumDepth[i] = sumDepth[i-1] + depthPhi[i];
    }
}

int main()
{
    modifiedSieve();
    int tc,m,n;
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d %d",&m,&n);
        printf("%d\n", sumDepth[n]-sumDepth[m-1]);
    }
}
