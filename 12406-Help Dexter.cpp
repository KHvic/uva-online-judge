#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,p,q;
    int tc = 1;
    cin >> t;
    while(t--){
        cin >> p >> q;
        pair<long long,long long> res = {LLONG_MAX,LLONG_MIN};
        for(int i=0;i<(1<<p);i++){
            long long num = 0;
            for(int j=0;j<p;j++){
                num *= 10;
                if(i & (1<<j)) num+=2;
                else num+=1;
            }
            // divisible if leftmost bit is >= 2^q
            if((num&(-num)) >= (1<<q)){
                res.first = min(res.first,num);
                res.second = max(res.second,num);
            }
        }
        printf("Case %d:",tc++);
        if(res.first == LLONG_MAX && res.second == LLONG_MIN)
            printf(" impossible");
        else if(res.first == res.second)
            printf(" %lld",res.first);
        else {
            if(res.first != LLONG_MAX) printf(" %lld",res.first);
            if(res.second != LLONG_MIN) printf(" %lld",res.second);
        }
        cout << endl;
    }
}
