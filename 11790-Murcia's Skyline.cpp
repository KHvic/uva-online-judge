#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,h,w,tc=1;
    scanf("%d",&t);
    while(t--){
        vector<int> LIS_dp;
        vector<int> LDS_dp;
        vector<int> heights;
        int maxLISWidth = 0, maxLDSWidth = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&h);
            heights.push_back(h);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&w);
            h = heights[i];
            int widthInc=0,widthDec=0;
            for(int j=0;j<i;j++){
                if(h > heights[j])
                    widthInc = max(LIS_dp[j],widthInc);
                if(h < heights[j])
                    widthDec = max(LDS_dp[j],widthDec);
            }
            LIS_dp.push_back(widthInc+w);
            LDS_dp.push_back(widthDec+w);
            maxLISWidth = max(maxLISWidth,LIS_dp.back());
            maxLDSWidth = max(maxLDSWidth,LDS_dp.back());
        }
        if(maxLISWidth >= maxLDSWidth)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",tc++,maxLISWidth,maxLDSWidth);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",tc++,maxLDSWidth,maxLISWidth);
    }
}
