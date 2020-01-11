#include <bits/stdc++.h>
using namespace std;

struct node {
    int dish;
    node *prev;
};
// state: days, budget, dish, count
double dp[22][101][51][2];
node dp_path[22][101][51][2];

int main() {
    int k,n,m,c,v;
    while(scanf("%d %d %d",&k,&n,&m), (k+n+m)) {
        vector<pair<int,int>> dishes;
        for(int i=0;i<n;i++){
            scanf("%d %d",&c,&v);
            dishes.push_back({c,v});
        }
        for(int i=0;i<=k;i++) //day
            for(int j=0;j<n;j++) // dish
                for(int t=0;t<2;t++) // repetition
                    for(int b=0;b<=m;b++) // budget
                        dp[i][b][j][t] = -1;

        double res = 0;
        int best_cost = INT_MAX;
        node *path;
        dp[0][0][0][0] = 0;
        dp_path[0][0][0][0].dish = -1;
        for(int i=0;i<=k;i++){ //day
            for(int j=0;j<n;j++){ // dish
                for(int t=0;t<2;t++){ // repetition
                    for(int b=0;b<=m;b++){ // budget
                        if(i == k) {
                            if(dp[i][b][j][t]>res || (dp[i][b][j][t]==res && b<best_cost)) {
                                res = dp[i][b][j][t];
                                best_cost = b;
                                path = &dp_path[i][b][j][t];
                            }
                            continue;
                        }
                        if(dp[i][b][j][t] == -1) continue;
                        for(int p=0;p<n;p++){ // next dish
                            tie(c,v) = dishes[p];
                            int cost = b+c;
                            int times = 0;
                            if(cost > m) continue;
                            double benefit = dp[i][b][j][t];
                            if(i==0 || j!=p) benefit += v;
                            else if(j==p && t==0) benefit += v/2.0, times=1;
                            else times=1;
                            if(benefit > dp[i+1][cost][p][times]) {
                                dp[i+1][cost][p][times] = benefit;
                                dp_path[i+1][cost][p][times].dish = p;
                                dp_path[i+1][cost][p][times].prev = &dp_path[i][b][j][t];
                            }
                        }
                    }
                }
            }
        }
        printf("%.1f\n",res);
        if(res != 0.0) {
            stack<int> rev;
            while(path->dish != -1) {
                rev.push(path->dish+1);
                path = path->prev;
            }
            while(!rev.empty()){
                printf("%d", rev.top()), rev.pop();
                if(rev.empty()) printf("\n");
                else printf(" ");
            }
        }
    }
}
