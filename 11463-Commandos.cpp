#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t,n,r,u,v,tc=1;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    vector<vector<int>> floyd(n,vector<int>(n,1e6));
    for(int i=0;i<n;i++) floyd[i][i] = 0;
    scanf("%d",&r);
    for(int i=0;i<r;i++){
        scanf("%d %d",&u,&v);
        floyd[u][v] = floyd[v][u] = 1;
    }
    scanf("%d %d",&u, &v);
    // floyd warshall
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                floyd[i][j] = min(floyd[i][j],floyd[i][k]+floyd[k][j]);
    int maxDist = INT_MIN;
    for(int i=0;i<n;i++)
        maxDist = max(maxDist,floyd[u][i]+floyd[i][v]);
    printf("Case %d: %d\n",tc++,maxDist);
  }
}
