#include <bits/stdc++.h>

using namespace std;

// Indepdent Set(IS) is the set of vertices such that no two vertices are connected by an edge
// Maximum Indepedent Set is an IS with the maximum number of vertices fulfilling such condition

int V,E,nS,mxS;
vector<long long> adjacentMatrix; // graph of bit adj matrix, what is i connected to?

// i - current vertex
// used - bitmask of length V denoting which vertices is no longer available
// depth - depth of recursion, also the size of the independent set
void rec(int i, long long used, int depth) {
    if (used == (1LL << V) - 1) { // all vertices are covered, Maximum Independent Set
        nS++; // one more possible set
        mxS = max(mxS, depth); // size of the set
    }
    else {
        for (int j = i; j < V; j++)
            if (!(used & (1LL << j))) // if vertex j is not yet covered yet
                rec(j + 1, used | adjacentMatrix[j], depth + 1); // fast bit operation, set all reachable node adjacent to j
    }
}

int main() {
    int tc,a,b;
    scanf("%d",&tc);
    while(tc--){
        nS = mxS = 0;
        scanf("%d %d",&V,&E);
        adjacentMatrix.assign(V,0);
        for(int i=0;i<V;i++) adjacentMatrix[i] = 1LL << i; // self directed

        for(int i=0;i<E;i++){
            scanf("%d %d",&a,&b);
            adjacentMatrix[a] |= (1LL<<b);
            adjacentMatrix[b] |= (1LL<<a);
        }
        rec(0,0,0);
        printf("%d\n%d\n",nS,mxS);
    }
}

