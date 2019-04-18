
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int n,m,v;
    while(scanf("%d %d\n",&n,&m),n){
        vector<tuple<int,bool,int>> vals;
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            vals.push_back(make_tuple(v,v%2 == 0,v%m));
        }
        sort(vals.begin(),vals.end(),[](tuple<int,bool,int>&a,tuple<int,bool,int>&b){
            if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
            if(get<1>(a) && get<1>(b)) return get<0>(a) < get<0>(b);
            if(!get<1>(a) && !get<1>(b)) return get<0>(a) > get<0>(b);
            return !get<1>(a);
        });
        printf("%d %d\n",n,m);
        for(auto& p : vals)
            cout << get<0>(p) << endl;
    }
    printf("0 0\n");
}
