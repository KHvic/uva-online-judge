#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100000;
struct Node{
    int maxH,minH,lazy;
};
Node segment[3*SIZE];
int res;

void update(int idx, int l, int r, int h, int qlow, int qhigh){
    // lazy update
    if(segment[idx].lazy) {
        // propagate update if it is not a leaf
        // range update to child
        if(l!=r){
            segment[idx*2+1].maxH = segment[idx*2+1].minH = segment[idx].lazy;
            segment[idx*2+2].maxH = segment[idx*2+2].minH = segment[idx].lazy;
            segment[idx*2+1].lazy = segment[idx*2+2].lazy = segment[idx].lazy;
        }
        segment[idx].lazy = 0;
    }
    // full overlap
    if(qlow<=l && r<=qhigh) {
        // higher than all buildings
        if(h >= segment[idx].maxH) {
            res += r-l+1;
            // set lazy to min & max
            segment[idx].maxH = segment[idx].minH = segment[idx].lazy = h;
            return;
        } else if(h < segment[idx].minH) {
            // its the smallest height in this interval already
            return;
        }
        // else in between, we should perform a split like partial overlap
    // no overlap
    } else if(qhigh < l || qlow > r) return;
    // partial overlap split
    // we execute code here if height is between min&max for full overlap case
    // as there exist segment(s) smaller than the height
    // or it is a actual partial overlap
    int mid = (l+r)/2;
    update(idx*2+1, l, mid, h, qlow, qhigh);
    update(idx*2+2, mid+1, r, h, qlow, qhigh);

    segment[idx].minH = min(segment[idx*2+1].minH,segment[idx*2+2].minH);
    segment[idx].maxH = max(segment[idx*2+1].maxH,segment[idx*2+2].maxH);
}

int main() {
    int t,n;
    int l,r,h;
    scanf("%d",&t);
    while(t--){
        cin >> n;
        res = 0;
        memset(segment,0,sizeof(segment));
        while(n--){
            cin >> l >> r >> h;
            update(0,0,SIZE,h,l,r-1);
        }
        cout << res << endl;
    }
}
