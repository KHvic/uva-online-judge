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
    int t,v;
    cin >> t;
    while(t--){
        set<int,greater<int>> vals;
        while(cin >> v, v){
            vals.insert(v);
        }
        long long total = 0;
        int i=1;
        for(auto it=vals.begin();it!=vals.end();it++){
            total += pow(*it,i++);
        }
        total *=2;
        if(total > 5000000)
            cout << "Too expensive" << endl;
        else
            cout << total << endl;
    }
}
