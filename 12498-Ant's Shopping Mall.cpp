#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t,r,c;
    char grid[51][51];
    int cases = 1;
    cin >> t;
    while(t--){
        cin >> r >> c;
        vector<vector<int>> stepToZero(r, vector<int>(c,c));
        for(int i=0;i<r;i++){
            scanf("%s", grid[i]);
            int prevZero = c;
            stack<int> prevOne;
            for(int j=0;j<c;j++){
                if(grid[i][j] == '0'){
                    stepToZero[i][j] = 0;
                    prevZero = j;
                    while(!prevOne.empty()){
                        stepToZero[i][prevOne.top()] = min(stepToZero[i][prevOne.top()], j-prevOne.top());
                        prevOne.pop();
                    }
                } else {
                    prevOne.push(j);
                    if(prevZero != c)
                        stepToZero[i][j] = min(stepToZero[i][j], j-prevZero);
                }
            }
        }
        int res = INT_MAX;
        bool valid = true;
        for(int col=0;col<c && valid;col++){
            int sum = 0;
            for(int row=0;row<r && valid;row++){
                if(stepToZero[row][col] == c) valid = false;
                else sum += stepToZero[row][col];
            }
            res = min(res,sum);
        }
        printf("Case %d: %d\n",cases++, valid ? res : -1);
    }
}
