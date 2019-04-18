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
    int n;
    int c,r;
    int cases = 1;
    scanf("%d\n",&n);
    while(n--){
        scanf("%d %d",&c, &r);
        set<int> res;
        // c-r = g*q, find all possible multiplier q
        int diff = c-r;
        cout << "Case #" << cases++ << ":";
        if(diff == 0){
            cout << " 0" << endl;
            continue;
        }
        for(int i=1;i*i<=diff;i++)
            if(diff%i == 0){
                res.insert(diff/i);
                res.insert(i);
            }
        for(auto i : res)
            if(i > r) cout << " " << i;
        cout << endl;
    }
}
