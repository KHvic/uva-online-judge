#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

bool setRange(bitset<1000001>& cal, int start, int ending) {
    for(int i=start;i<ending && i<1000001;i++){
        if(cal[i]) return true;
        else cal[i] = true;
    }
    return false;
}

int main() {
    int n,m,s,e,c;
    while(scanf("%d %d",&n,&m),n || m){
        bitset<1000001> cal;
        bool hasConflict = false;
        while(n--){
            cin >> s >> e;
            if(!hasConflict) hasConflict = setRange(cal,s,e);
        }
        while(m--){
            cin >> s >> e >> c;
            int interval = e-s;
            while(!hasConflict && s<1000001){
                hasConflict = setRange(cal,s,e);
                s += c;
                e += c;
            }
        }
        cout << (hasConflict ? "CONFLICT" : "NO CONFLICT") << endl;
    }
}
