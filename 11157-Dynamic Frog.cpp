#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,d,v,tc=1;
    string in;
    cin >> t;
    while(t--){
        cin >> n >> d;
        vector<pair<bool,int>> stones(1,{true,0});
        int maximum = 0;
        for(int i=0;i<=n;i++){
            int loc;
            if(i<n){
                cin >> in;
                loc = stoi(in.substr(2));
            } else loc = d;
            // compare with previous stone if last one is a big
            // compare with i-2 stone if last one is a small (we can ignore previous stone since it is the min or used)
            int distToPrev = loc - (stones.back().first ? stones.back().second : stones[stones.size()-2].second);
            maximum = max(distToPrev,maximum);
            stones.push_back({in[0]=='B',loc});
        }
        printf("Case %d: %d\n",tc++,maximum);
    }
}
