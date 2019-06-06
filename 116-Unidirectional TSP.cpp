#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,v;
    while(scanf("%d %d",&n,&m) != EOF){
        vector<vector<int>> grid;
        vector<vector<int>> path(n,vector<int>(m,1e7));
        for(int i=0;i<n;i++){
            vector<int> row;
            for(int j=0;j<m;j++){
                cin >> v;
                row.push_back(v);
            }
            grid.push_back(row);
        }
        int res = 0;
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int a = (j-1+n)%n;
                int b = j;
                int c = (j+1)%n;
                int least = min(grid[a][i+1],min(grid[b][i+1],grid[c][i+1]));
                if(grid[a][i+1] == least) path[j][i] = min(path[j][i],a);
                if(grid[b][i+1] == least) path[j][i] = min(path[j][i],b);
                if(grid[c][i+1] == least) path[j][i] = min(path[j][i],c);
                grid[j][i] += least;
            }
        }
        int bestStarting = 0;
        int best = 1e7;
        for(int i=0;i<n;i++){
            if(grid[i][0] < best){
                bestStarting = i;
                best = grid[i][0];
            }
        }
        int cur = bestStarting;
        printf("%d",cur+1);
        for(int i=0;i<m-1;i++){
            cur = path[cur][i];
            printf(" %d",cur+1);
        }
        printf("\n%d\n",best);
    }
}
