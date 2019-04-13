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

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        vector<vector<int> > res(9,vector<int>());
        int cur;
        int prev;
        for(int i=0;i<9;i+=2){
            scanf("%d",&prev);
            res[i].push_back(prev);
            for(int j=0;j<i/2;j++){
                scanf("%d",&cur);
                // solve for previous missing item
                // Target = Prev + Cur + 2*Missing
                int targetIndex = res[i].size()-1;
                int target = res[i-2][targetIndex];
                int missing = (target - prev - cur)/2;
                res[i].push_back(missing);
                res[i].push_back(cur);
                // solve missing row
                res[i-1].push_back(missing+prev);
                res[i-1].push_back(missing+cur);
                prev = cur;
            }
        }
        for(auto vec : res){
            for(auto& i : vec)
                cout << i << (&i != &vec.back() ? " " : "\n");
        }
    }
}
