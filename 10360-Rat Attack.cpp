#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,d,n;
    int x,y,s;
    cin >> t;
    while(t--){
        cin >> d >> n;
        vector<vector<int>> dpSum(1026,vector<int>(1026));
        for(int i=0;i<n;i++){
            cin >> x >> y >> s;
            dpSum[x+1][y+1] += s;
        }
        int bestCount = 0;
        pair<int,int> coord = {0,0};
        for(int i=0;i<1025;i++){
            for(int j=0;j<1025;j++){
                dpSum[i+1][j+1] += (dpSum[i][j+1] + dpSum[i+1][j] - dpSum[i][j]);
                int xoffset = i-2*d < 0 ? 0 : i-2*d;
                int yoffset = j-2*d < 0 ? 0 : j-2*d;
                // perform query from 2d length from current point
                int res = dpSum[i+1][j+1]-dpSum[xoffset][j+1]-dpSum[i+1][yoffset]+dpSum[xoffset][yoffset];
                if(res>bestCount){
                    bestCount = res;
                    coord = {i-d,j-d}; //middle point
                }
            }
        }
        printf("%d %d %d\n", coord.first,coord.second,bestCount);
    }
}
