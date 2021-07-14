#include <bits/stdc++.h>
using namespace std;

vector<int> cars;
int memo[201][10001];
bool useLeft[201][10001];
int t,l,v;

int knapsack(int idx,int leftRemain,int rightRemain){
    if(idx == cars.size()) return 0;
    if(leftRemain - cars[idx] < 0 && rightRemain - cars[idx] < 0) return 0;
    if(memo[idx][leftRemain] != -1) return memo[idx][leftRemain];
	
    if (leftRemain - cars[idx] < 0) { 
	    return memo[idx][leftRemain] = 1 + knapsack(idx + 1, leftRemain, rightRemain - cars[idx]);
    }
    if (rightRemain - cars[idx] < 0) { 
	    useLeft[idx][leftRemain] = true;
	    return memo[idx][leftRemain] = 1 + knapsack(idx + 1, leftRemain - cars[idx], rightRemain);
    }
    int left = knapsack(idx+1,leftRemain-cars[idx],rightRemain);
    int right = knapsack(idx+1,leftRemain,rightRemain-cars[idx]);

    if(left >= right)
        useLeft[idx][leftRemain] = true;
    return memo[idx][leftRemain] = max(1 + left, 1 + right);
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
