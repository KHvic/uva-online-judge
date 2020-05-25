#include <bits/stdc++.h>
using namespace std;

// get last survivor of josephus iteration
int josephus(int n, int k) {
    int s = 0;
    for(int i=2;i<=n;i++)
        s = (s+k)%i; // next person after the one that is killed
    return s+1;
}

int main() {
    int t,n;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        scanf("%d",&n);
        int iteration = 0;
        while(1) {
            int survive = josephus(n, 2);
            iteration++;
            if(survive == n) break;
            n = survive;
        }
        printf("Case %d: %d %d\n", tc, iteration-1, n);
    }
}
