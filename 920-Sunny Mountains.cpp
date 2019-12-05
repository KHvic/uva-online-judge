#include <bits/stdc++.h>

using namespace std;

// struct point_i { int x, y; }; // basic raw form, minimalist mode
struct point {
    int x, y; // whenever possible, work with point_i
    point() { x = y = 0; } // default constructor
    point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        return x > other.x;
    }
}; // user-defined

double dist(point p1, point p2) { // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
} // return double

int main(){
    int c,n,x,y;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        vector<point> mountain;
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            mountain.push_back(point(x,y));
        }
        // start from the last point
        sort(mountain.begin(), mountain.end());

        int maxY = 0;
        double res = 0;
        for(int i=1;i<n;i++){
            if(mountain[i].y > maxY) {
                res += dist(mountain[i], mountain[i - 1]) * (mountain[i].y - maxY) / (mountain[i].y - mountain[i-1].y);
                maxY = mountain[i].y;
            }
        }
        printf("%0.2f\n",res);
    }
}
