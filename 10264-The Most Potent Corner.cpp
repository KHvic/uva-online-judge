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
    int d, v;
    while(scanf("%d",&d) != EOF){
        vector<int> weights;
        vector<int> potency;
        for(int i=0; i< 1<<d;i++){
            scanf("%d",&v);
            weights.push_back(v);
        }
        int best = 0;
        for(int i=0;i< 1<<d;i++){
            int cur = 0;
            for(int j=0;j<d;j++){
                cur += weights[i^(1<<j)];
            }
            potency.push_back(cur);
        }
        for(int i=0;i< 1<<d;i++)
            for(int j=0;j<d;j++)
                best = max(best,potency[i] + potency[i^(1<<j)]);
        cout << best << endl;
    }
}
