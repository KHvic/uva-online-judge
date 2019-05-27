#include <bits/stdc++.h>
using namespace std;

int ans[501] = {};
int gcd[501][501] = {};

int compute(int x,int y){
    return x == 0 ? y : compute(y%x,x);
}

int main() {
    for(int i=1;i<501;i++){
        for(int j=i+1;j<501;j++){
            gcd[i][j] = gcd[i][j-1] + compute(i,j);
            ans[j] += gcd[i][j];
        }
    }
    int n;
    while(scanf("%d",&n),n){
        printf("%d\n",ans[n]);
    }
}
