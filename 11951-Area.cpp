#include <bits/stdc++.h>
using namespace std;

// O(N^3) colSum dp

int main()
{
    int t,n,m,budget,tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&budget);
        vector<vector<int>> vec(n,vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&vec[i][j]);

        int bestArea = 0;
        long long curSum,bestCost=0;
        for(int i=0;i<n;i++){ // start row
            vector<int> colSumDp(m);
            for(int j=i;j<n;j++){ // end row
                int left = 0, curSum = 0;
                for(int k=0;k<m;k++){// each col
                    colSumDp[k] += vec[j][k];
                    curSum += colSumDp[k];
                    // above budget, perform sliding to cut cost
                    while(curSum > budget) curSum -= colSumDp[left++];
                    int area = (j-i+1)*(k-left+1);
                    // better area or better cost, update
                    if(area > bestArea){
                        bestArea = area;
                        bestCost = curSum;
                    } else if(area == bestArea && curSum < bestCost){
                        bestCost = curSum;
                    }
                }
            }
        }
        printf("Case #%d: %d %d\n",tc++,bestArea,bestCost);
    }
}
