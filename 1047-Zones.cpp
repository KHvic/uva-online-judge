#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,b,v,s,g;
    int tc=1;
    while(scanf("%d %d\n",&n,&b),n||b){
        vector<int> towers;
        for(int i=0;i<n;i++){
            cin >> v;
            towers.push_back(v);
        }
        cin >> g;
        vector<pair<int,int>> groups;
        for(int i=0;i<g;i++){
            cin >> s;
            int group = 0;
            for(int j=0;j<s;j++){
                cin >> v;
                group |= 1<<(v-1);
            }
            cin >> v;
            groups.push_back({group,v});
        }
        int best = 0;
        int bestGroup = 0;
        for(int i=1;i<(1<<n);i++){
            int gSize = 0;
            int sum = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    gSize++;
                    sum += towers[j];
                }
            }
            if(gSize != b) continue;
            for(int j=0;j<groups.size();j++){
                gSize = 0;
                int cur = groups[j].first;
                while(cur){
                    // least significant bit is in i
                    if(i & (cur&-cur)) gSize++;
                    cur &= (cur-1);
                }
                if(gSize>1) sum -= (groups[j].second*(gSize-1));
            }
            if(sum > best){
                best = sum;
                bestGroup = i;
            }
        }
        printf("Case Number  %d\n",tc++);
        printf("Number of Customers: %d\n",best);
        printf("Locations recommended:");
        for(int i=0;i<n;i++)
            if((1<<i)&bestGroup) printf(" %d",i+1);
        cout << endl << endl;
    }
}
