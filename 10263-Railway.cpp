#include <bits/stdc++.h>

using namespace std;
#define EPS 1e8

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) { // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b) { // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s);
} // shorter.same.longer
point translate(point p, vec v) { // translate p according to v
    return point(p.x + v.x , p.y + v.y);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab, projecting point p on line a-b
    vec ap = toVec(a, p), ab = toVec(a, b);
    // dot product gives us scale of ap on ab (projection), and we further normalize it for translation
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c); // Euclidean distance between p and c
}

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = point(a.x, a.y); // closer to a
    return dist(p, a); } // Euclidean distance between p and a
    if (u > 1.0) { c = point(b.x, b.y); // closer to b
    return dist(p, b); } // Euclidean distance between p and b
    return distToLine(p, a, b, c);
}

int main() {
    int n;
    point m;
    double a1,b1,a2,b2;
    while(scanf("%lf %lf",&m.x,&m.y) != EOF){
        scanf("%d",&n);
        point p1,p2,c,best_p;
        scanf("%lf %lf",&p1.x,&p1.y);
        double best = DBL_MAX;
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&p2.x,&p2.y);
            double res = distToLineSegment(m,p1,p2,c);
            p1 = p2;
            if(res < best) {
                best = res;
                best_p = c;
            }
        }
        printf("%.4f\n%.4f\n",best_p.x,best_p.y);
    }
}
