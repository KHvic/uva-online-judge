#include <bits/stdc++.h>

using namespace std;
int z,i,m,l;

int main()
{
    int tc=1;
    while(scanf("%d %d %d %d",&z,&i,&m,&l),(z+i+m+l)) {
        int slow = l, fast = l;
        auto f = [](int x) {
            return (z*x+i)%m;
        };
        int res = 0;
        while(true) {
            slow = f(slow);
            fast = f(f(fast));
            res++;
            if(fast == slow) break;
        }
        printf("Case %d: %d\n",tc++,res);
    }
}
