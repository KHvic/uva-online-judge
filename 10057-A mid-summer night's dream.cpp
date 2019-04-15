
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int main() {
    int a, v;
    while(cin >> a){
        vector<int> ll;
        while(a--) {
            cin >> v;
            ll.push_back(v);
        }
        sort(ll.begin(), ll.end());
        int r1,r2,r3;
        r1 = ll[(ll.size()-1)/2];
        r2 = upper_bound(ll.begin(),ll.end(),r1) - lower_bound(ll.begin(),ll.end(),r1);
        if(ll.size() % 2){
            r3 = 1;
        } else {
            r3 = ll[(ll.size()-1)/2] == ll[ll.size()/2] ? 1 : ll[ll.size()/2] - ll[(ll.size()-1)/2] + 1;
            if(r3 != 1){
                int otherMedian = ll[ll.size()/2];
                r2 += upper_bound(ll.begin(),ll.end(),otherMedian) - lower_bound(ll.begin(),ll.end(),otherMedian);
            }
        }
        printf("%d %d %d\n",r1,r2,r3);
    }
}
