#include <bits/stdc++.h>
using namespace std;
#define EPS 0.001

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

double dist(point p1, point p2) { // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
vec toVec(point a, point b) { // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

point pivot(0, 0);
bool angleCmp(point a, point b) { // angle-sorting function
    if (collinear(pivot, a, b)) // special case
        return dist(pivot, a) < dist(pivot, b); // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
} // compare two angles

// graham scan
vector<point> CH(vector<point> P)
{
    // step 1: pivot finding
    int i,N=(int)P.size();
    int po=0;
    for (i=0;i<N-1;i++)
        if(P[i].y < P[po].y || (P[i].y== P[po].y && P[i].x < P[po].x))
            po=i;
    pivot = P[po];

    // step 2: sorting
    sort(P.begin(),P.end(),angleCmp);

    // step 3: stack ccw test
    point prev(0,0),now(0,0);
    stack<point> S;
    S.push(pivot);
    i=1;
    while(i<N)
    {
        if(S.size()<2)
        {
            S.push(P[i++]);
        }
        else{
            now = S.top();
            S.pop();
            prev=S.top();
            S.push(now);
            if(ccw(prev,now,P[i]))
                S.push(P[i++]);
            else S.pop();
        }
    }

    vector<point> ConvexHull;
    ConvexHull.push_back(pivot);
    while(!S.empty())
    {

        ConvexHull.push_back(S.top());
        S.pop();
    }
    return ConvexHull;
}

int main() {
    int k,n,x,y;
    scanf("%d",&k);
    printf("%d\n",k);
    for(int tc=1;tc<=k;tc++){
        scanf("%d",&n);
        vector<point> P;
        while(n--){
            scanf("%d %d",&x,&y);
            P.push_back(point(x,y));
        }
        vector<point> convexHull = CH(P);
        printf("%d\n",convexHull.size());
        for(auto p = convexHull.rbegin(); p != convexHull.rend(); p++)
            printf("%d %d\n",(int)p->x,(int)p->y);
        if(tc != k) {
            scanf("%d",&n);
            printf("-1\n");
        }
    }
}
