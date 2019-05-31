#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,tc=1;
    bool newline = false;
    while(scanf("%d",&v), v != -1){
        if(tc>1) printf("\n");
        vector<int> res(1,v);
        while(scanf("%d",&v), v != -1){
            auto it = lower_bound(res.rbegin(),res.rend(),v);
            if(it == res.rbegin()) res.push_back(v);
            else *prev(it) = v;
        }
        printf("Test #%d:\n",tc++);
        printf("  maximum possible interceptions: %d\n",(int)res.size());
    }
}
