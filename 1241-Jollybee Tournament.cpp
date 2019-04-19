#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>
using namespace std;

int main()
{
    int t,n,m,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int nums = pow(2,n);
        bitset<1024> bits;
        bits.set();
        while(m--){
            cin >> v;
            bits.reset(v-1);
        }
        int res = 0;
        while(nums){
            int idx = 0;
            for(int i=1;i<nums;i+=2){
                res += (bits.test(i) ^ bits.test(i-1));
                bits[idx++] = bits.test(i) | bits.test(i-1);
            }
            nums >>= 1;
        }
        cout << res << endl;
    }
}
