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

int computeDist(string& a){
    int dist = 26;
    for(int i=1;i<a.length();i++)
        dist = min(abs(a[i]-a[i-1]),dist);
    return dist;
}

int main(){
    string in;
    while(getline(cin,in), !in.empty()){
        string best = in;
        int maxDist = computeDist(best);
        string curPrev = in;
        bool hasPrev = true;
        bool hasNext = true;
        string curNext = in;
        for(int i=0;i<10;i++){
            hasPrev = hasPrev ? prev_permutation(curPrev.begin(),curPrev.end()) : false;
            hasNext = hasNext ? next_permutation(curNext.begin(),curNext.end()) : false;
            int dist = computeDist(curPrev);
            if(hasPrev && dist >= maxDist) {
                maxDist = dist;
                best = curPrev;
            }
            dist = computeDist(curNext);
            if(hasNext && dist > maxDist) {
                maxDist = dist;
                best = curNext;
            }
        }
        cout << best << maxDist << endl;
    }
}
