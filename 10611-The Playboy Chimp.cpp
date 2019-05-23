#include <bits/stdc++.h>
using namespace std;
// use lower_bound then prev
// use upper_bound

// own implementation of ceil, floor in one method exclude target
int ceilOrFloor(vector<int>& vec, int target, bool floor){
    int low = 0;
    int high = vec.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(vec[mid] == target){
            if(floor) high = mid-1;
            else low = mid+1;
        } else if(vec[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return floor ? high : low;
}


int main()
{
    int n,q,v;
    vector<int> chimps;
    cin >> n;
    while(n--){
        cin >> v;
        chimps.push_back(v);
    }
    cin >> q;
    while(q--){
        cin >> v;
        int floor = ceilOrFloor(chimps,v,true);
        int ceil = ceilOrFloor(chimps,v,false);
        if(floor>=0) printf("%d ",chimps[floor]);
        else printf("X ");
        if(ceil<chimps.size()) printf("%d\n",chimps[ceil]);
        else printf("X\n");
    }
}
