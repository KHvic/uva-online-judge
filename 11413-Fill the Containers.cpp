#include <bits/stdc++.h>
using namespace std;

bool can(vector<int>& vessels, int cap, int m){
    int remain = cap;
    for(auto& milk : vessels){
        // milk will overflow max cap?
        if(milk > cap) return false;
        if(milk > remain) {
            // use next container
            if(--m == 0) return false;
            remain = cap;
        }
        remain -= milk;
    }
    return true;
}

int main()
{
    int n,m,v;
    while(scanf("%d %d",&n,&m) != EOF){
        vector<int> vessels;
        int lo,hi=0;
        for(int i=0;i<n;i++){
            cin >> v;
            vessels.push_back(v);
            hi += v;
        }
        lo = hi/vessels.size();
        // lower_bound (bisect-left)
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(can(vessels,mid,m)) hi = mid;
            else lo = mid+1;
        }
        printf("%d\n",lo);
    }
}
