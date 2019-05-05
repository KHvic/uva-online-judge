#include <bits/stdc++.h>
using namespace std;
// find x,y such that x*y = k*y+k*x
// y = (x*k)/(x-k), if check x*k with mod of x-k, then there exist a y

int main() {
    int k;
    while(scanf("%d",&k) != EOF){
        vector<pair<int,int>> res;
        // check until 2*k, the highest possible val for x or y
        for(int x=k+1;x<=2*k;x++){
            if(((x*k) % (x-k)) != 0) continue;
            int y = (x*k)/(x-k);
            res.push_back({y,x});
        }
        cout << res.size() << endl;
        for(auto& p : res){
            printf("1/%d = 1/%d + 1/%d\n",k,p.first,p.second);
        }
    }
}
