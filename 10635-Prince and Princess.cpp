#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,p,q,v,tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&p,&q);
        vector<int> lcs; // also lis of position
        unordered_map<int,int> valToPos; // valToPos for the prince
        for(int i=0;i<=p;i++){
            scanf("%d",&v);
            valToPos[v] = i;
        }
        for(int i=0;i<=q;i++){
            scanf("%d",&v);
            int pos = valToPos[v];
            if(pos == 0) continue;
            auto insertion = lower_bound(lcs.begin(),lcs.end(),pos);
            // greedy, take lower position
            if(insertion == lcs.end()) lcs.push_back(pos);
            else *insertion = pos;
        }
        printf("Case %d: %d\n", tc++, lcs.size()+1);
    }
}
