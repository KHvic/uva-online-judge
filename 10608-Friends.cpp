#include <bits/stdc++.h>
using namespace std;

int groupSize[30000];
int highest;

int udfsFind(int* udfs, int n){
    return udfs[n] == n ? n : udfsFind(udfs,udfs[n]);
}

void udfsJoin(int* udfs, int a, int b){
    if(udfsFind(udfs,a) == udfsFind(udfs,b)) return;
    int newSize = groupSize[udfsFind(udfs,a)] += groupSize[udfsFind(udfs,b)];
    highest = max(newSize,highest);
    udfs[udfsFind(udfs,b)] = udfsFind(udfs,a);
}

int main() {
    int t,n,m,a,b;
    cin >> t;
    while(t--){
        cin >> n >> m;
        highest = 1;
        int udfs[n];
        for(int i=0;i<n;i++){
            groupSize[i] = 1;
            udfs[i] = i;
        }
        for(int i=0;i<m;i++){
            cin >> a >> b;
            udfsJoin(udfs,a-1,b-1);
        }
        cout << highest << endl;
    }
}
