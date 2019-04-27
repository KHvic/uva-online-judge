#include <bits/stdc++.h>
using namespace std;

int udfsFind(int*group,int n){
    return group[n] == n ? n : group[n] = udfsFind(group,group[n]);
}

void udfsJoin(int*group,int a,int b,vector<int>& groupSize){
    int parA = udfsFind(group,a);
    int parB = udfsFind(group,b);
    if(parA == parB) return;
    group[parB] = parA;
    groupSize[parA] += groupSize[parB];
}

int main() {
    int n,m,v;
    int s;
    while(scanf("%d %d",&n,&m),n){
        int group[n] = {};
        vector<int> groupSize(n,1);
        for(int i=0;i<n;i++) group[i] = i;
        for(int i=0;i<m;i++){
            cin >> s;
            int prev = -1;
            while(s--){
                cin >> v;
                if(prev != -1) udfsJoin(group,prev,v,groupSize);
                prev = v;
            }
        }
        v = udfsFind(group,0);
        cout << groupSize[v] << endl;
    }
}
