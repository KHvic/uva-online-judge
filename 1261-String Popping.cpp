#include <bits/stdc++.h>
using namespace std;

unordered_map<string,bool> valid;

bool canEmpty(string in){
    if(in.empty()) return true;
    if(valid.count(in)) return valid[in];
    int i=0;
    bool can = false;
    while(i<in.length() && !can){
        int j = i;
        while(j+1<in.length() && in[j+1] == in[i]) j++;
        if(j!=i) can = canEmpty(in.substr(0,i) + in.substr(j+1));
        i = j + 1;
    }
    return valid[in] = can;
}

int main()
{
    int t;
    string in;
    cin >> t;
    while(t--){
        cin >> in;
        valid.clear();
        if(canEmpty(in)) printf("1\n");
        else printf("0\n");
    }
}
