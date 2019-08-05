#include <bits/stdc++.h>

using namespace std;
int n;
int parent[21][21][21];
double dist[21][21][21];

void printPath(int i,int j,int d){
    if(d==0){
        printf("%d %d",i+1,j+1);
    } else {
        printPath(i,parent[i][j][d],d-1);
        printf(" %d",j+1);
    }
}

int main() {
    while(scanf("%d",&n) != EOF){
        memset(parent,0,sizeof parent);
        memset(dist,0,sizeof dist);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) dist[i][j][0] = 1;
                else
                    scanf("%lf", &dist[i][j][0]);
            }
        }
        // floyd warshall with number of moves as additional state
        for(int d=1;d<n;d++){
            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        double nextCost = dist[i][k][d-1]*dist[k][j][0];
                        if(nextCost > dist[i][j][d]){
                            dist[i][j][d] = nextCost;
                            parent[i][j][d] = k;
                            if(i==j && nextCost >= 1.01){
                                printPath(i,j,d);
                                printf("\n");
                                goto success;
                            }
                        }
                    }
                }
            }
        }
        printf("no arbitrage sequence exists\n");
        success: ;
    }
}
