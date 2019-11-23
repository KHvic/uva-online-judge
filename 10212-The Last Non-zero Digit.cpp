#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF) {
        long long res = 1;
        for(int i=n;i>n-m;i--) {
            res *= i;
            while(res%10 == 0) res/=10;
            res %= 1000000000;
        }
        printf("%d\n",res%10);
    }
}
