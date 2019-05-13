#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p,v,a,t;
    int tc=1;
    while(scanf("%d",&p),p){
        vector<int> programs;
        for(int i=0;i<p;i++){
            cin >> v;
            programs.push_back(v);
        }
        sort(programs.begin(),programs.end());
        cin >> a;
        vector<pair<int,int>> aligns;
        for(int i=0;i<a;i++){
            cin >> v >> t;
            aligns.push_back({t,v});
        }
        sort(aligns.begin(),aligns.end());
        vector<int> best(5,INT_MAX);
        vector<int> bestOrder;
        do {
            vector<int> missTime(5,0);
            int j = 0;
            int curTime = 0;
            for(int i=0;i<aligns.size();i++){
                while(j<programs.size() && aligns[i].first >= curTime+programs[j]){
                    curTime += programs[j++];
                }
                int lowerDiff = aligns[i].first - curTime;
                int upperDiff = 
                    j<programs.size() ? curTime + programs[j] - aligns[i].first : INT_MAX;
                missTime[aligns[i].second-1] += min(lowerDiff, upperDiff);
            }
            if(missTime < best){
                bestOrder = programs;
                best = missTime;
            }
        } while(next_permutation(programs.begin(),programs.end()));
        
        int sum = 0;
        for(auto& i : best) sum+= i;
        
        printf("Data set %d\n",tc++);
        printf("Order:");
        for(auto& i : bestOrder) cout << " " << i;
        cout << endl;
        printf("Error: %d\n", sum);
    }
}
