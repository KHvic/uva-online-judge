#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,b,j,tc=1;
    while(scanf("%d",&n),n){
        vector<pair<int,int>> soldiers;
        for(int i=0;i<n;i++){
            cin >> b >> j;
            soldiers.push_back({b,j});
        }
        // fix all other, select two for time comparison
        auto cmp = [](const pair<int,int>& a,const pair<int,int>& b){
            int first = max(a.first+b.first+b.second,a.first+a.second);
            int second = max(b.first+a.first+a.second,b.first+b.second);
            return first < second;
        };
        sort(soldiers.begin(),soldiers.end(),cmp);
        int totalBriefTime = 0;
        int maxCompletionTime = 0;
        for(auto& soldier : soldiers){
            totalBriefTime += soldier.first;
            // soldier x can complete his job = totalBriefTime + his jobTime
            maxCompletionTime = max(maxCompletionTime,totalBriefTime+soldier.second);
        }
        printf("Case %d: %d\n",tc++,maxCompletionTime);
    }
}
