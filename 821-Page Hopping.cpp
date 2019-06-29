#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,tc=1;
    while(scanf("%d %d",&a,&b),(a+b)!=0){
        vector<vector<int>> graph(101,vector<int>(101,1e6));
        int maxN = 1;
        do {
            maxN = max(maxN,max(a,b));
            graph[a][b] = 1;
        } while(scanf("%d %d",&a,&b), (a+b)!=0);

        // floyd-warshall
        for(int k=1;k<=maxN;k++)
            for(int i=1;i<=maxN;i++)
                for(int j=1;j<=maxN;j++)
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);

        int sum=0,cnt=0;
        for(int i=1;i<=maxN;i++)
            for(int j=1;j<=maxN;j++)
                if(i!=j && graph[i][j] < 1e6){
                    cnt++;
                    sum+=graph[i][j];
                }

        printf("Case %d: average length between pages = %.3f clicks\n",tc++, (double)sum/cnt);
    }
}
