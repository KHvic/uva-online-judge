#include <bits/stdc++.h>
using namespace std;

unsigned long long memo[62][62];

unsigned long long trib(int n, unsigned int back)
{
    if(n <= 1) return 1;
    else if(memo[n][back] != 0) return memo[n][back];
    // start with 1 as this function is called
    unsigned long long sum = 1;
    for(int i=1;i<=back;i++) sum += trib(n-i,back);

    return memo[n][back] = sum;
}

int main()
{
    int a,b,tc=1;
    while(scanf("%d %d",&a,&b) != EOF){
        if(a > 60) break;
        printf("Case %d: %llu\n",tc++,trib(a,b));
    }
}
