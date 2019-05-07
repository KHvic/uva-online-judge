#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,v;
    int cases = 1;
    while(scanf("%d",&n),n){
        vector<int> vals;
        while(n--){
            cin >> v;
            vals.push_back(v);
        }
        vector<int> sum;
        for(int i=0;i<vals.size();i++)
            for(int j=i+1;j<vals.size();j++)
                sum.push_back(vals[i]+vals[j]);
        sort(sum.begin(),sum.end());
        cin >> m;
        printf("Case %d:\n",cases++);
        while(m--){
            cin >> v;
            auto upper = lower_bound(sum.begin(),sum.end(),v);
            auto lower = lower_bound(sum.begin(),sum.end(),v);
            if(lower != sum.begin()) --lower;
            int res;
            if(upper==sum.end()) res = *lower;
            else
                res = abs(v-*lower) < abs(v-*upper) ? *lower : *upper;
            printf("Closest sum to %d is %d.\n",v,res);
        }
    }
}
