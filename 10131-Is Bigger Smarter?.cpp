#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w,s;
    int i=1;
    vector<tuple<int,int,int>> elephants;
    while(scanf("%d %d",&w,&s)!=EOF){
        elephants.push_back(make_tuple(w,s,i++));
    }
    auto cmp = [](const tuple<int,int,int>& a,const tuple<int,int,int>& b){
        if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    };
    sort(elephants.begin(),elephants.end(),cmp);

    vector<int> dp;
    vector<int> parent;
    int bestIdx = 0, best = 0;
    for(int i=0;i<elephants.size();i++){
        int prev = -1, longest=0;
        for(int j=0;j<i;j++){
            if(get<0>(elephants[i]) > get<0>(elephants[j]) &&
               get<1>(elephants[i]) < get<1>(elephants[j]) &&
               dp[j] > longest){
                longest = dp[j];
                prev = j;
            }
        }
        parent.push_back(prev);
        dp.push_back(longest+1);
        if(dp.back() > best){
            best = dp.back();
            bestIdx = i;
        }
    }
    stack<int> res;
    while(bestIdx != -1){
        res.push(get<2>(elephants[bestIdx]));
        bestIdx = parent[bestIdx];
    }
    printf("%d\n",best);
    while(!res.empty()) printf("%d\n",res.top()), res.pop();
}
