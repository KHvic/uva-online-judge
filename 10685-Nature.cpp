#include <bits/stdc++.h>
using namespace std;

unordered_map<string,string> pars;
unordered_map<string,int> groupSize;
int best;

string udfsFind(string& n){
    return pars[n] == n ? n : pars[n] = udfsFind(pars[n]);
}

void join(string& a, string& b){
    string parA = udfsFind(a);
    string parB = udfsFind(b);
    if(parA == parB) return;
    groupSize[parA] += groupSize[parB];
    best = max(best, groupSize[parA]);
    pars[parB] = parA;
}

int main()
{
    int c,r;
    string a,b;
    while(scanf("%d %d",&c,&r),c||r){
        pars.clear();
        groupSize.clear();
        best = 1;
        for(int i=0;i<c;i++){
            cin >> a;
            pars[a] = a;
            groupSize[a] = 1;
        }
        for(int i=0;i<r;i++){
            cin >> a >> b;
            join(a,b);
        }
        cout << best << endl;
    }
}
