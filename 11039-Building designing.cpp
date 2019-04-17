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
using namespace std;

int main() {
    int t,f,v;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d\n",&f);
        vector<int> neg;
        vector<int> pos;
        int prev = 0;
        int res = 0;
        while(f--) {
            cin >> v;
            if(v>0) pos.push_back(v);
            else neg.push_back(v);
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end(),greater<int>());
        auto pStart = pos.begin();
        auto nStart = neg.begin();
        while(prev == 0 || (prev>0 && nStart != neg.end()) || (prev<0 && pStart != pos.end())){
            if(prev == 0){
                prev = abs(*nStart) < *pStart ? *nStart : *pStart;
                if(prev == *pStart) pStart++;
                else nStart++;
                res++;
            } else if(prev < 0){
                if(*pStart > abs(prev)){
                    prev = *pStart;
                    res++;
                }
                pStart++;
            } else {
                if(abs(*nStart) > prev){
                    prev = *nStart;
                    res++;
                }
                nStart++;
            }
        }
        cout << res << endl;
    }
}
