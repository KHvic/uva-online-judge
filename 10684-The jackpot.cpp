#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,v;
    while(scanf("%d",&n),n){
        int cur = 0,best = 0;
        for(int i=0;i<n;i++){
            cin >> v;
            cur = max(0,cur+v);
            best = max(best,cur);
        }
        if(best) printf("The maximum winning streak is %d.\n",best);
        else printf("Losing streak.\n");
    }
}
