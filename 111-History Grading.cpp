#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,v;
    scanf("%d",&n);
    vector<int> pos(n);
    for(int i=0;i<n;i++){
        cin >> v;
        pos[i] = v;
    }
    while(scanf("%d",&v) != EOF){
        vector<int> res;
        vector<int> guess(n);
        guess[v-1] = 0;
        for(int i=1;i<n;i++){
            cin >> v;
            guess[v-1] = i; // event i is at v
        }
        for(int i=0;i<n;i++){
            int target = pos[guess[i]];
            auto it = lower_bound(res.begin(),res.end(),target);
            if(it == res.end()) res.push_back(target);
            else *it = min(*it,target);
        }
        printf("%d\n",(int)res.size());
    }
}
