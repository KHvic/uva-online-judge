#include <bits/stdc++.h>
using namespace std;

int t1,t2,n,m,cost;
vector<int> sites;
vector<vector<int>> ncpcCost;
vector<vector<int>> bcewCost;
int memo[301][301][31];
int choice[301][301][31];

int topdown(int remNCPC, int remBCEW, int idx){
    if(idx == n) return 0;
    if(memo[remNCPC][remBCEW][idx] != -1)
        return memo[remNCPC][remBCEW][idx];
    int best = 1e7;
    for(int a=0;a<=sites[idx];a++){
        int b = sites[idx] - a;
        if(a>remNCPC || b>remBCEW) continue;
        int res = topdown(remNCPC-a,remBCEW-b,idx+1);
        res += (ncpcCost[idx][a] + bcewCost[idx][b]);
        if(res < best){
            best = res;
            choice[remNCPC][remBCEW][idx] = a;
        }
    }
    return memo[remNCPC][remBCEW][idx] = best;
}

int main()
{
    while(scanf("%d %d",&t1,&t2), t1||t2){
        scanf("%d",&n);
        sites.clear();
        ncpcCost.clear();
        bcewCost.clear();
        memset(memo,-1,sizeof memo);
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            vector<int> siteA(1,0);
            vector<int> siteB(1,0);
            for(int j=0;j<2*m;j++){
                scanf("%d",&cost);
                if(j<m) siteA.push_back(cost);
                else siteB.push_back(cost);
            }
            sites.push_back(m);
            ncpcCost.push_back(siteA);
            bcewCost.push_back(siteB);
        }
        printf("%d\n",topdown(t1,t2,0));
        for(int i=0;i<n;i++){
            int a = choice[t1][t2][i];
            int b = sites[i]-a;
            printf("%d",a);
            if(i+1 == n) printf("\n");
            else printf(" ");
            t1 -= a; t2 -= b;
        }
        printf("\n");
    }
}
