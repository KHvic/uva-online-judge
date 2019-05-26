#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> coins;
        for(int i=0;i<n;i++){
            cin >> v;
            coins.push_back(v);
        }
        int curSum = 0, res=0;
        for(int i=0;i<n;i++)
        // sum should not surpass next larger coin, else it will yield worst result
        // include smallest coins without surpassing next coin value
        if(n-1 == i || curSum+coins[i]<coins[i+1]){
            curSum += coins[i];
            res++;
        }
        printf("%d\n",res);
    }
}
