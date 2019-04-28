#include <bits/stdc++.h>
using namespace std;

int groupCount;

int udfsFind(int* udfs, int n){
    return udfs[n] == n ? n : udfsFind(udfs,udfs[n]);
}

void udfsJoin(int* udfs, int a, int b){
    if(udfsFind(udfs,a) == udfsFind(udfs,b)) return;
    udfs[udfsFind(udfs,a)] = udfsFind(udfs,b);
    groupCount--;
}

int main() {
    int n,m,a,b;
    int cases=1;
    while(scanf("%d %d",&n,&m),n||m){
        int udfs[n];
        groupCount = n;
        for(int i=0;i<n;i++) udfs[i] = i;
        for(int i=0;i<m;i++){
            cin >> a >> b;
            udfsJoin(udfs,a-1,b-1);
        }
        printf("Case %d: %d\n",cases++,groupCount);
    }
}
