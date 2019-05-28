#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,v;
    while(scanf("%d",&n),n){
        long long cur = 0, res = 0;
        for(int i=0;i<n;i++){
            cin >> v;
            cur += v;
            // positive indicate I want wine to be moved here
            // negative, wines have to be shifted from here
            // so either way, add them as part of result
            res += abs(cur);
        }
        printf("%lld\n",res);
    }
}
