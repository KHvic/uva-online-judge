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
    int a,b;
    while(scanf("%d %d",&a,&b) != EOF) {
        extendedEuclid(a,b);
        printf("%d %d %d\n",x,y,d);
    }
}
