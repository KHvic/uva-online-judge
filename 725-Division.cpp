#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    bool notfirst = false;
    while(scanf("%d",&n),n){
        if(notfirst) cout << endl;
        notfirst = true;
        bool found = false;
        for(int fghij = 1234; fghij <= 98765 / n; fghij++ ) {
            int abcde = fghij * n;
            int tmp, used = (fghij < 10000); // leading zero, set bit
            tmp = abcde;
            while(tmp){
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while(tmp){
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if(used == (1<<10)-1){
                printf("%0.5d / %0.5d = %d\n",abcde,fghij,n);
                found = true;
            }
        }
        if(!found)
            printf("There are no solutions for %d.\n",n);
    }
}
