#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        bool valid = false;
        for(int a=0;a*a<n && !valid;a++)
        for(int b=a;b*b+a*a<n && !valid;b++){
            int c2 = n - a*a - b*b;
            double c = sqrt(c2);
            if(c2 >= 0 && c-round(c) == 0){
                valid = true;
                printf("%d %d %d\n",a,b,(int)c);
            }
        }
        if(!valid) printf("-1\n");
    }
}
