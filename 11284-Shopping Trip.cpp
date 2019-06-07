#include <bits/stdc++.h>
using namespace std;

int t,n,m,a,b,p;
double cost;
int memo[1<<13][13]; // tsp state
int dist[51][51]; // shortest path
int storeNum[13]; // map pos i to actual store index
int savings[13]; // savings from pos i

int tsp(int pos, int bitmask){
    // visited all stores
    if(bitmask == ((1<<p)-1)) return -dist[0][storeNum[pos]];
    if(memo[bitmask][pos] != -1e7) return memo[bitmask][pos];

    int best = -dist[0][storeNum[pos]];
    for(int i=0;i<p;i++)
        if(!(bitmask &(1<<i))){
            best = max(best, tsp(i,bitmask|(1<<i)) + savings[i] - dist[storeNum[pos]][storeNum[i]]);
        }
    return memo[bitmask][pos] = best;
}

int main()
{
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dist[i][j] = 1e8;
        for(int i=0;i<m;i++){
            cin >> a >> b >> cost;
            dist[b][a] = dist[a][b] = min(dist[a][b],(int)round(cost*100));
        }
        // floyd warshall
        for(int k=0;k<=n;k++)
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        cin >> p;
        memset(savings,0,sizeof savings);
        for(int i=0;i<(1<<p);i++)
            for(int j=0;j<=p;j++)
                memo[i][j] = -1e7;
        for(int i=0;i<p;i++){
            cin >> storeNum[i] >> cost;
            savings[i] += round(cost*100);
        }
        int res = 0;
        for(int i=0;i<p;i++)
            res = max(tsp(i,1<<i)-dist[storeNum[i]][0]+savings[i], res);
        if(res == 0)
			puts("Don't leave the house");
		else
			printf("Daniel can save $%.2f\n", res/100.0);
    }
}
