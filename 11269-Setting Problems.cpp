
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,v;
    while(scanf("%d",&n) != EOF){
        vector<pair<int,int>> res(n);
        for(int i=0;i<2*n;i++){
            cin >> v;
            if(i<n) res[i].first = v;
            else res[i-n].second = v;
        }
        // compare only two job's total time with all the rest fixed
        auto cmp = [](const pair<int,int>& a , const pair<int,int>& b){
            int aFirst = a.first+max(a.second,b.first)+b.second;
            int bFirst = b.first+max(b.second,a.first)+a.second;
            return aFirst < bFirst;
        };
        sort(res.begin(),res.end(),cmp);
        int sultanTime = 0;
        int golaTime = 0;
        for(int i=0;i<res.size();i++){
            sultanTime += res[i].first;
            // gola depends on sultan totalTime & his own previous finish time
            golaTime = max(sultanTime,golaTime)+res[i].second;
        }
        printf("%d\n",golaTime);
    }
}
