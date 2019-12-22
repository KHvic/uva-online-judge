#include <bits/stdc++.h>
using namespace std;

int n,v,tc=1;

// actually can just use a set instead of unordered_set
// custom vector hash
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

vector<int> cutPaste(int len, int start, int to, const vector<int>& cur) {
    vector<int> res(cur.size());
    for(int i=0;i<len;i++) res[to+i] = cur[start+i];
    int insertIdx = 0;
    for(int i=0;i<cur.size();i++){
        if(i < start || i >= start+len) {
            while(res[insertIdx] != 0) insertIdx++;
            res[insertIdx] = cur[i];
        }
    }
    return res;
}

int main() {
    while(scanf("%d",&n),n){
        vector<int> para, target;
        int steps = 1;
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            para.push_back(v);
            target.push_back(i+1);
        }
        if (para != target) {
        // bidirectional bfs on smaller depth side
        unordered_set<vector<int>, VectorHash> beginSet, endSet, visitedSet;
        beginSet.insert(para), endSet.insert(target);
        visitedSet.insert(para), visitedSet.insert(target);
        int depthBegin = 0, depthEnd = 0;
        while(!beginSet.empty() || !endSet.empty()) {
            if(depthEnd < depthBegin) {
                  swap(endSet, beginSet);
                  swap(depthBegin, depthEnd);
            }
            unordered_set<vector<int>, VectorHash> nextSet;
            for(auto& s : beginSet) {
                for(int i=1;i<n;i++) // size to shift
                    for(int j=0;j+i<=n;j++) // starting point
                        for(int k=0;k<n-i;k++){
                            int low = j, high = j+i+1;
                            if(k >= low && k <= high) continue;
                            vector<int> next = cutPaste(i,j,k,s);
                            if(endSet.count(next)) {
                                goto done;
                            }
                            if(visitedSet.count(next)) continue;
                            visitedSet.insert(next);
                            nextSet.insert(next);
                        }
            }
            beginSet = nextSet;
            depthBegin++;
            steps++;
        }
        } else { steps = 0; }
        done: ;
        printf("Case %d: %d\n",tc++,steps);
    }
}
