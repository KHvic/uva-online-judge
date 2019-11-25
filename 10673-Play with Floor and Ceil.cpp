#include <bits/stdc++.h>
using namespace std;

int x,y,d;

// ax + by = d
// store x, y, and d as global variables
void extendedEuclid(int a, int b) {
    if (b == 0) { x = 1; y = 0; d = a; return; } // base case
    extendedEuclid(b, a % b); // similar as the original gcd
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main() {
    int x1,k,t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&x1,&k);
        int a = x1/k, b = (int)ceil((double)x1/k);
        extendedEuclid(a,b);
        // ax + by = d
        // to get to x1, we multiply whole equation by x1/d
        x *= x1/d;
        y *= x1/d;
        printf("%d %d\n",x,y);
    }
}
