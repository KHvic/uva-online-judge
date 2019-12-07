#include <bits/stdc++.h>

using namespace std;
#define EPS 1e8

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const { // override less than operator
        if (fabs(x - other.x) > EPS) // useful for sorting
            return x < other.x; // first criteria , by x-coordinate
        return y < other.y;
    }
};

double dist(point p1, point p2) { // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
    (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

int main() {
    int n;
    double rad;
    point c;
    while(scanf("%d",&n), n){
        vector<point> polygon;
        for(int i=0;i<n;i++) {
            point p;
            scanf("%lf %lf",&p.x,&p.y);
            polygon.push_back(p);
        }
        scanf("%lf",&rad);
        bool foundCircle = false;
        for(int i=0;i<n && !foundCircle;i++){
            for(int j=0;j<n && !foundCircle;j++){
                if(i==j) continue;
                circle2PtsRad(polygon[i],polygon[j],rad,c);
                foundCircle = true;
                for(int k=0;k<n && foundCircle;k++)
                    if(dist(polygon[k],c) > rad) foundCircle = false;
            }
        }
        if(foundCircle) printf("The polygon can be packed in the circle.\n");
        else printf("There is no way of packing that polygon.\n");
    }
}

