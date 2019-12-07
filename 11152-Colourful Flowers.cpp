#include <bits/stdc++.h>

using namespace std;
#define PI 2*acos(0)

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) { // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double perimeter(double a, double b, double c) {return a+b+c;}
double area(double a, double b, double c) {
    // heron's formula
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// inscribed circle has radius of A/s
double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}
double rInCircle(point a, point b, point c) {
    return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// circumcircle of triangle has radius = a*b*c/(4*A)
double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
double rCircumCircle(point a, point b, point c) {
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

int main() {
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c) != EOF){
        double rInner = rInCircle(a,b,c);
        double rOuter = rCircumCircle(a,b,c);

        double areaInner = rInner*rInner*PI;
        double areaTriangle = area(a,b,c) - areaInner;
        double areaOuter = rOuter*rOuter*PI - areaInner - areaTriangle;
        printf("%.4f %.4f %.4f\n",areaOuter,areaTriangle,areaInner);
    }
}

