#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,v,tc=1;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> rungs(1,0);
        int maxDiff = 0;
        for(int i=0;i<n;i++){
            cin >> v;
            maxDiff = max(maxDiff,v-rungs.back());
            rungs.push_back(v);
        }
        // answer is either maxDiff or maxDiff+1
        int curStrength = maxDiff;
        for(int i=1;i<rungs.size();i++)
        if(rungs[i]-rungs[i-1] > curStrength) {
            maxDiff++;
            break;
        } else if(rungs[i]-rungs[i-1] == curStrength){
            curStrength--;
        }
        printf("Case %d: %d\n",tc++,maxDiff);
    }
}
