#include <bits/stdc++.h>
using namespace std;

vector<int> cars;
int memo[200][10001];
bool useLeft[200][10001];
int t,l,v;

int knapsack(int idx,int leftRemain,int rightRemain){
    if(leftRemain<=0 && rightRemain<=0) return 0;
    if(idx == cars.size()) return 0;
    // memo centered on leftRemain
    // we don't have to care about rightRemain
    // since total space used/left at idx is always the same, just center on one of them
    if(memo[idx][leftRemain] != -1) return memo[idx][leftRemain];
    // try both right and left
    int left=0,right=0;
    if(rightRemain >= cars[idx])
        right = knapsack(idx+1,leftRemain,rightRemain-cars[idx])+1;
    if(leftRemain >= cars[idx])
        left = knapsack(idx+1,leftRemain-cars[idx],rightRemain)+1;

    if(left > right)
        useLeft[idx][leftRemain] = true;
    return memo[idx][leftRemain] = max(left,right);
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&l);
        l *= 100;
        cars.clear();
        memset(memo,-1,sizeof(memo));
        memset(useLeft,0,sizeof(useLeft));
        while(scanf("%d",&v),v) cars.push_back(v);
        int res = knapsack(0,l,l);
        printf("%d\n",res);
        int leftRemain = l;
        for(int i=0;i<res;i++){
            if(useLeft[i][leftRemain]){
                printf("port\n");
                leftRemain -= cars[i];
            } else {
                printf("starboard\n");
            }
        }
        if(t) printf("\n");
    }
}
