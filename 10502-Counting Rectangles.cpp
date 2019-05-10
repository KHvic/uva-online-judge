#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,v;
    char grid[101];
    while(cin >> n, n){
        cin >> m;
        vector<vector<int>> dpSum(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++) {
            scanf("%s",grid);
            for(int j=1;j<=m;j++){
                dpSum[i][j] = dpSum[i-1][j] + dpSum[i][j-1] - dpSum[i-1][j-1];
                dpSum[i][j] += (grid[j-1]-'0');
            }
        }
        int res = 0;
        //foreach starting coordinate topleft
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //foreach ending coordinate btmright
                for(int k=i;k<=n;k++){
                    for(int l=j;l<=m;l++){
                        int fullSquare = (k-i+1)*(l-j+1);
                        int filledAmt = dpSum[k][l] - (dpSum[k][j-1] + dpSum[i-1][l] - dpSum[i-1][j-1]);
                        if(fullSquare == filledAmt) res++;
                    }
                }
            }
        }
        cout << res << endl;
    }
}
