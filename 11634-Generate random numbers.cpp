#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%lld",&n),n){
        auto f = [](int x) {
            return (x*x/100)%10000;
        };
        int res = 1;
        int slow = n, fast = n;
        while(true){
            slow = f(slow);
            fast = f(f(fast));
            if(slow == fast) break;
        }
        slow = n;
        while(slow != fast){
            slow = f(slow), fast = f(fast);
            res++;
        }
        slow = f(fast);
        while(slow != fast) {
            res++;
            slow = f(slow);
        }
        printf("%d\n",res);
    }
}
