#include <bits/stdc++.h>
using namespace std;

int fenwickNeg[100002]; // fenwick for neg count
int fenwickZero[100002]; // fenwick for zero count
int val[100002];
int n;

pair<int,int> query(int i){
    int sumNeg = 0;
    int sumZero = 0;
    while(i>0){
        sumNeg += fenwickNeg[i];
        sumZero += fenwickZero[i];
        i -= (i&-i);
    }
    return {sumNeg,sumZero};
}

pair<int,int> mainQuery(int i, int j){
    pair<int,int> right = query(j);
    pair<int,int> left = query(i-1);
    return {right.first-left.first, right.second-left.second};
}

void update(int i, int v){
    int diffZero = v == 0 ? 1 : 0;
    int diffNeg = v < 0 ? 1 : 0;
    if(val[i] == 0) diffZero -= 1;
    if(val[i] < 0) diffNeg -= 1;
    val[i] = v;
    while(i<=n){
        fenwickNeg[i] += diffNeg;
        fenwickZero[i] += diffZero;
        i += (i&-i);
    }
}

int main() {
    int k,v;
    char c;
    int l,r;
    while(scanf("%d %d",&n,&k) != EOF){
        memset(fenwickNeg,0,sizeof(int)*(n+1));
        memset(fenwickZero,0,sizeof(int)*(n+1));
        for(int i=1;i<=n;i++){
            val[i] = 2; // arbitrary pos number
            scanf("%d",&v);
            update(i, v);
        }
        for(int i=0;i<k;i++){
            cin >> c >> l >> r;
            if(c == 'C') update(l,r);
            else {
                pair<int,int> res = mainQuery(l,r);
                if(res.second) cout << "0";
                else if(res.first % 2) cout << "-";
                else cout << "+";
            }
        }
        cout << endl;
    }
}
