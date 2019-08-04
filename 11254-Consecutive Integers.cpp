#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n),n!=-1){
        // brute force from higher range
        for(int range=sqrt(2*n); range>0; range--){
            // arithmetic series to find first number
            int first = (2*n+range-range*range);
            if(first%(2*range)==0){
                first/=(2*range);
                printf("%d = %d + ... + %d\n",n,first,first+range-1);
                break;
            }
        }
    }
}
