#include <bits/stdc++.h>
using namespace std;

int m, c, price[25][25];
int memo[210][25];

// money left, garment index
int shop(int money, int g) {
    if(money < 0) return -1e9;
    if(g == c) return m - money;
    // has memo
    if(memo[money][g] != -1)
        return memo[money][g];
    int bestRes = -1;
    for(int i=1;i<=price[g][0];i++){
        bestRes = max(shop(money-price[g][i],g+1),bestRes);
    }
    return memo[money][g] = bestRes;
}

int main()
{
    int score,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&c);
        for(int i=0;i<c;i++){
            // store size to [0]
            scanf("%d",&price[i][0]);
            for(int j=1;j<=price[i][0];j++)
                scanf("%d",&price[i][j]);
        }
        memset(memo,-1,sizeof(memo));
        score = shop(m,0);
        if(score < 0) printf("no solution\n");
        else printf("%d\n",score);
    }
}
