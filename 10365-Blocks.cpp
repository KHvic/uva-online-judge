#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int res = INT_MAX;
        // find any square surface
        for(int l=1;l<=sqrt(n);l++)
        for(int h=l;h<=sqrt(n);h++)
        // check if exist width for such n,l,h
        if((n%h) == 0 && ((n/h)%l) == 0){
            int w = (n/h)/l;
            res = min(res, 2*l*w+2*h*w+2*l*h);
        }
        cout << res << endl;
    }
}
