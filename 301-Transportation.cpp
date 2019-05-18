#include <bits/stdc++.h>
using namespace std;
int res;

void dfs(int idx,vector<tuple<int,int,int>>& orders,vector<int>& capacity,
         int earn,int limit){
    if(idx == orders.size()){
        res = max(res,earn);
        return;
    }
    // without this order
    dfs(idx+1,orders,capacity,earn,limit);
    // with this order
    int s,d,p;
    tie(s,d,p) = orders[idx];
    capacity[s] += p;
    capacity[d] -= p;
    // validate can fit
    int sum = 0;
    bool canFit = true;
    for(int i=0;i<=d && canFit;i++){
        sum += capacity[i];
        if(sum > limit) canFit = false;
    }
    if(canFit) dfs(idx+1,orders,capacity,(d-s)*p+earn,limit);
    capacity[s] -= p;
    capacity[d] += p;
}

int main()
{
    int n,s,o;
    int st,d,p;
    while(scanf("%d %d %d",&n,&s,&o),n||s||o){
        vector<tuple<int,int,int>> orders;
        vector<int> capacity(s+1);
        for(int i=0;i<o;i++){
            cin >> st >> d >> p;
            orders.push_back(make_tuple(st,d,p));
        }
        res = 0;
        dfs(0,orders,capacity,0,n);
        cout << res << endl;
    }
}
