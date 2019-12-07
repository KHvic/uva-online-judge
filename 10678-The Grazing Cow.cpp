#include <bits/stdc++.h>

using namespace std;
#define PI 2*acos(0)

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

// area of ellipse = a*b*pi, where a and b are half of minor and major axes
int main() {
    int n;
    double d,l;
    scanf("%d",&n);
    while(n--) {
        scanf("%lf %lf",&d,&l);
        double a = l/2;
        double b = sqrt(l/2*l/2-d/2*d/2);
        double area = PI*a*b;
        printf("%.3f\n",area);
    }
}
