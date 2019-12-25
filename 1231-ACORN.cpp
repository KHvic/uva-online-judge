#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> acorn; // dp array, dp[tree][height]
    // dp trick for saving time complexity is to use another shortcut dp of height, same as dp[for all][height h]
    vector<int> dp; // dp[height] shortcut to obtain best from all tree
    int tc;
    int t,h,f,a,v;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d %d",&t,&h,&f);
        acorn.assign(t+1,vector<int>(h+1,0));
        dp.assign(h+1,0);
        for(int i=0;i<t;i++){
            scanf("%d",&a);
            for(int j=0;j<a;j++){
                scanf("%d",&v);
                acorn[i][v]++;
            }
        }

        // init
        for(int tree=0;tree<t;tree++)
            dp[h] = max(dp[h], acorn[tree][h]);
        // from top of tree
        for(int height=h-1;height>=0;height--){
            for(int tree=0;tree<t;tree++){
                int add = acorn[tree][height+1];
                if(height+f <= h)
                    add = max(add, dp[height+f]);
                acorn[tree][height] += add; // best for dp[tree][height]
                dp[height] = max(dp[height],acorn[tree][height]);
            }
        }
        printf("%d\n", dp[0]);
    }
}
