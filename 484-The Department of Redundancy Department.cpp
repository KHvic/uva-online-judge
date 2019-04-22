#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    unordered_map<int,int> valToIdx;
    vector<pair<int,int>> res;
    int v;
    while(cin >> v){
        if(!valToIdx.count(v)){
            valToIdx[v] = res.size();
            res.push_back({v,0});
        }
        int idx = valToIdx[v];
        res[idx].second++;
    }
    for(auto it=res.begin();it!=res.end();it++)
        cout << it->first << " " << it->second << endl;
}
