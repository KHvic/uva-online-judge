#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,v,tc=1;
    while(scanf("%d",&t),t){
        vector<int> best_buy = {0};
        int best_profit = 0;
        for(int i=0;i<t;i++){
            scanf("%d",&n);
            int best = 0;
            vector<int> next_buy = {0};
            int cur_earn = 0;
            for(int j=0;j<n;j++){
                scanf("%d",&v);
                cur_earn += (10-v);
                if(cur_earn > best) {
                    best = cur_earn;
                    next_buy.clear();
                }
                if(cur_earn == best) {
                    next_buy.push_back(j+1);
                }
            }
            set<int> new_buy;
            for(int cur : best_buy)
                for(int next : next_buy)
                    new_buy.insert(cur + next);
            best_buy.clear();
            best_profit += best;
            auto it = new_buy.begin();
            for(int i=0;i<10&&it!=new_buy.end();i++) best_buy.push_back(*it++);
        }
        if(tc>1) printf("\n");
        printf("Workyards %d\n",tc++);
        printf("Maximum profit is %d.\n",best_profit);
        printf("Number of pruls to buy:");
        for(int cur : best_buy) printf(" %d",cur);
        printf("\n");
    }
}
