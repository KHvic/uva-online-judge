#include <bits/stdc++.h>
using namespace std;
// quick 2D segment tree
int treeMin[501*2][501*2];
int treeMax[501*2][501*2];
int n;

void update1D(int idx, int y, int val){
    y += n;
    treeMin[idx][y] = treeMax[idx][y] = val;
    for(int i=y>>1;i>0;i>>=1) {
        treeMin[idx][i] = min(treeMin[idx][i*2],treeMin[idx][i*2+1]);
        treeMax[idx][i] = max(treeMax[idx][i*2],treeMax[idx][i*2+1]);
    }
}

void update2D(int x, int y, int val){
    x += n;
    update1D(x,y,val);
    for(int i=x>>1;i>0;i>>=1) {
        for(int j=y+n;j>0;j>>=1){
            treeMin[i][j] = min(treeMin[i*2][j],treeMin[i*2+1][j]);
            treeMax[i][j] = max(treeMax[i*2][j],treeMax[i*2+1][j]);
        }
    }
}

pair<int,int> query1D(int idx, int left, int right){
    pair<int,int> res = {INT_MAX,INT_MIN};
    for(left+=n,right+=n; left<=right; left>>=1, right>>=1){
        if(left&1){
            res.first = min(res.first,treeMin[idx][left]);
            res.second = max(res.second,treeMax[idx][left++]);
        }
        if((right&1)==0){
            res.first = min(res.first,treeMin[idx][right]);
            res.second = max(res.second,treeMax[idx][right--]);
        }
    }
    return res;
}

pair<int,int> query2D(int rowTop, int rowBtm, int colLeft, int colRight){
    pair<int,int> res = {INT_MAX,INT_MIN};
    for(rowTop+=n,rowBtm+=n; rowTop<=rowBtm; rowTop>>=1, rowBtm>>=1){
        if(rowTop&1){
            pair<int,int> subRes = query1D(rowTop++,colLeft,colRight);
            res.first = min(res.first,subRes.first);
            res.second = max(res.second,subRes.second);
        }
        if((rowBtm&1) == 0){
            pair<int,int> subRes = query1D(rowBtm--,colLeft,colRight);
            res.first = min(res.first,subRes.first);
            res.second = max(res.second,subRes.second);
        }
    }
    return res;
}

void build1D(int idx,vector<int>& rowVals){
    idx += n;
    for(int i=0;i<n;i++) treeMin[idx][i+n] = treeMax[idx][i+n] = rowVals[i];
    for(int i=n-1;i>0;i--) {
        treeMin[idx][i] = min(treeMin[idx][i*2],treeMin[idx][i*2+1]);
        treeMax[idx][i] = max(treeMax[idx][i*2],treeMax[idx][i*2+1]);
    }
}

void build2D() {
    for(int i=n-1;i>0;i--) {
        for(int j=1;j<2*n;j++){
            treeMin[i][j] = min(treeMin[i*2][j], treeMin[i*2+1][j]);
            treeMax[i][j] = max(treeMax[i*2][j], treeMax[i*2+1][j]);
        }
    }
}

int main() {
    int v,q;
    int x1,y1,x2,y2;
    char c;
    cin >> n;
    for(int i=0;i<n;i++){
        vector<int> rowVals;
        for(int j=0;j<n;j++){
            cin >> v;
            rowVals.push_back(v);
        }
        build1D(i, rowVals);
    }
    // build 2d segment tree based on 1d
    build2D();
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> c;
        if(c == 'q'){
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;
            pair<int,int> res = query2D(x1,x2,y1,y2);
            cout << res.second << " " << res.first << endl;
        } else {
            cin >> x1 >> y1 >> v;
            x1--; y1--;
            update2D(x1,y1,v);
        }
    }
}
