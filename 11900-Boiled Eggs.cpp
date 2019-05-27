#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,p,q,v,tc=1;
    cin >> t;
    while(t--){
        cin >> n >> p >> q;
        int res = 0, totalWeight=0;
        for(int i=0;i<n;i++){
            cin >> v;
            if(totalWeight+v <= q && res<p){
                totalWeight += v;
                res++;
            }
        }
        printf("Case %d: %d\n",tc++,res);
    }
}
