#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    string k,v;
    unordered_map<string,string> slogan;
    scanf("%d\n",&n);
    while(n--){
        getline(cin,k);
        getline(cin,v);
        slogan[k] = v;
    }
    scanf("%d\n",&q);
    while(q--){
        getline(cin,k);
        cout << slogan[k] << endl;
    }
}
