#include <bits/stdc++.h>
using namespace std;
// idea, check if we can do without a certain bit or add a bit
int main()
{
    unsigned int m,l,u;
    while(scanf("%u %u %u",&m,&l,&u) != EOF){
        unsigned int cur = 0;
        for(int i=31;i>=0;i--){
            if(((1<<i)&m) == 0){
                // bit is not set, try to set it if <= upper
                unsigned int newNum = cur|(1<<i);
               if(newNum <= u) cur = newNum;
            } else {
                // bit is set, try to unset it if we can still fulfill constraint
                // largest possible without the i bit
                unsigned int largestPossible = cur | ((1<<i)-1); // assume we set all subsequence bits later
                if(largestPossible < l) cur |= (1<<i); // we need the bit so that cur >= lower
            }
        }
        cout << cur << endl;
    }
}
