#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,n,v,tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n/2;i++) scanf("%d",&v);
        scanf("%d",&v);
        printf("Case %d: %d\n",tc++,v);
        for(int i=0;i<n/2;i++) scanf("%d",&v);
    }
}
