#include <bits/stdc++.h>

using namespace std;

int vals[367][800];
int digitCount[367][10];

void precompute(){
    memset(vals, 0, sizeof vals);
    memset(digitCount, 0, sizeof digitCount);
    vals[0][0] = 1, digitCount[0][1] = 1;
    for(int i=1;i<=366;i++) {
        for(int j=0;j<=783;j++) {
            vals[i][j] += vals[i-1][j]*i;
            vals[i][j+1] += vals[i][j]/10;
            vals[i][j] %= 10;
        }
        bool started = false;
        for(int j=783;j>=0;j--) {
            if(vals[i][j]) started = true;
            if(started)
                digitCount[i][vals[i][j]]++;
        }
    }
}

int main()
{
    precompute();
    int n;
    while(scanf("%d",&n), n){
        printf("%d! --\n   ",n);
        for(int i=0;i<5;i++) {
            if(i) printf("    ");
            printf("(%d)%5d", i, digitCount[n][i]);
        }
        printf("\n   ");
        for(int i=5;i<10;i++) {
            if(i>5) printf("    ");
            printf("(%d)%5d", i, digitCount[n][i]);
        }
        printf("\n");
    }
}
