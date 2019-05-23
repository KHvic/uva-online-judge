#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,d,k;
    cin >> t;
    while(t--){
        cin >> d >> k;
        int cur = 1;
        for(int i=1;i<d;i++){
            if(k%2){
                // odd, go left
                k = k/2+1;
                cur *= 2;
            } else {
                // even, go right
                k/=2;
                cur = cur*2+1;
            }
        }
        printf("%d\n",cur);
    }
    cin >> t;
}
