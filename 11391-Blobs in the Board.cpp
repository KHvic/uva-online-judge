#include <bits/stdc++.h>
using namespace std;

int t,r,c,n,x,y,tc=1;
int memo[5][5][1<<16];

int solve(int bitmask)
{
    if((bitmask&(bitmask-1))==0) return 1;
    else if(memo[r][c][bitmask] != -1) return memo[r][c][bitmask];

    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(bitmask &(1<<(i*c+j))) {
                for(int a=-1;a<2;a++)
                for(int b=-1;b<2;b++)
                if(a!=0 || b!=0){
                    int nextX1=i+a, nextY1=j+b;
                    int nextX2=nextX1+a, nextY2=nextY1+b;
                    if(nextX2<0 || nextX2>=r || nextY2<0 || nextY2>=c) continue;
                    if((bitmask & (1<<(nextX1*c+nextY1))) && !(bitmask & (1<<(nextX2*c+nextY2)))){
                        int next_bitmask = bitmask ^ (1<<(i*c+j));
                        next_bitmask ^= (1<<(nextX1*c+nextY1)) ^ (1<<(nextX2*c+nextY2));
                        cnt += solve(next_bitmask);
                    }
                }
            }
        }
    }
    return memo[r][c][bitmask] = cnt;
}

int main()
{
    memset(memo, -1, sizeof memo);
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&r,&c,&n);
        int bitmask = 0;
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            x--; y--;
            bitmask |= (1<<(x*c+y));
        }
        printf("Case %d: %d\n",tc++,solve(bitmask));
    }
}
