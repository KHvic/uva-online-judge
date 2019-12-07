#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) { // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() {
    int n, a;
    while(scanf("%d %d",&n,&a),(n+a)) {
        int m = 0;
        vector<point> corners{
            point(0,0), point(a,0), point(a,a), point(0,a)
        };
        for(int i=0;i<n;i++){
            point p;
            scanf("%lf %lf",&p.x,&p.y);
            bool within = true;
            for(auto& corner : corners){
                double euc = dist(p, corner);
                if(euc > a) {
                    within = false;
                    break;
                }
            }
            if(within) m++;
        }
        printf("%.5f\n", (double)m/n*a*a);
    }
}

