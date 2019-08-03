#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc=1;
    double r,n;
    while(scanf("%lld %lld",&r,&n),(r+n)!=0){
        int needed = ceil(r/n)-1;
        printf("Case %d: ",tc++);
        if(needed<=26) printf("%d\n",needed);
        else printf("impossible\n");
    }
}
