#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;

int main() {
    int t;
    string in;
    while(scanf("%d",&t), t){
        vector<string> vals;
        while(t--){
            cin >> in;
            vals.push_back(in);
        }
        sort(vals.begin(),vals.end(),[](string& a, string& b){
                return a+b > b+a;
             });
        for(auto&s : vals) cout<<s;
        cout << endl;
    }
}
