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
using namespace std;

int main() {
    int v, y, a, b;
    int cases=1;
    while(scanf("%d",&v), v){
        vector<int> diff;
        vector<int> display;
        int cur = 0;
        for(int i=0;i<v;i++){
            cin >> y >> a >> b;
            diff.push_back(b-a);
            display.push_back(y);
            cur = max(y,cur);
        }
        for(;cur<10000;cur++){
            bool correct = true;
            for(int j=0;j<diff.size() && correct;j++){
                if(((cur-display[j])%diff[j]) != 0) correct = false;
            }
            if(correct) break;
        }
        cout << "Case #" << cases++ << ":" << endl;
        if(cur<10000) cout << "The actual year is " << cur << "." << endl;
        else cout << "Unknown bugs detected." << endl;
        cout << endl;
    }
}
