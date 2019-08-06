#include <bits/stdc++.h>
using namespace std;

// Pisano Period: the last 1,2,3,4 digits of fibonacci seq
// repeats with a period of 60/300/1500/15000

vector<int> period = {60,300,1500,15000};
vector<int> mod = {10,100,1000,10000};

int main()
{
    int t,a,b,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&a,&b,&n,&m);
        // generate seq up to period
        n %= period[m-1];
        vector<int> fib;
        fib.push_back(a % mod[m-1]), fib.push_back(b % mod[m-1]);
        for(int i=2;i<=n;i++)
            fib.push_back((fib[i-1]+fib[i-2]) % mod[m-1]);
        printf("%d\n",fib[n]);
    }
}
