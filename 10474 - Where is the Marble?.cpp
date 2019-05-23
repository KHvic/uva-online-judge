#include <bits/stdc++.h>
using namespace std;

// or use lower_bound function
// bisect_left allow us to find the first leftmost insertion spot
int bisect_left(vector<int>& marb, int target){
    int low = 0;
    int high = marb.size()-1;
    while(low<high){
        int mid = (low+high)/2;
        if(target > marb[mid]) low = mid+1;
        else high = mid;
    }
    return low;
}

int main()
{
    int n,q,v,tc=1;
    pair<int,int> left,right,mid;
    while(scanf("%d %d",&n,&q),n||q){
        vector<int> marb;
        for(int i=0;i<n;i++){
            cin >> v;
            marb.push_back(v);
        }
        sort(marb.begin(),marb.end());
        printf("CASE# %d:\n",tc++);
        while(q--){
            cin >> v;
            int pos = bisect_left(marb,v);
            if(marb[pos] == v) printf("%d found at %d\n",v,pos+1);
            else printf("%d not found\n",v);
        }
    }
}
