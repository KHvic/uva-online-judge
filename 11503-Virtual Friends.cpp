#include <bits/stdc++.h>
using namespace std;

unordered_map<string,string> pars;
unordered_map<string,int> groupSize;

string udfsFind(string& n){
    return pars[n] == n ? n : pars[n] = udfsFind(pars[n]);
}

int join(string& a, string& b){
    string parA = udfsFind(a);
    string parB = udfsFind(b);
    if(parA == parB) return groupSize[parA];
    groupSize[parA] += groupSize[parB];
    pars[parB] = parA;
    return groupSize[parA];
}

int main()
{
    int n,r;
    cin >> n;
    string a,b;
    while(n--){
        cin >> r;
        pars.clear();
        groupSize.clear();
        for(int i=0;i<r;i++){
            cin >> a >> b;
            if(!pars.count(a)){
                pars[a] = a;
                groupSize[a] = 1;
            }
            if(!pars.count(b)){
                pars[b] = b;
                groupSize[b] = 1;
            }
            cout << join(a,b) << endl;
        }
    }
}
