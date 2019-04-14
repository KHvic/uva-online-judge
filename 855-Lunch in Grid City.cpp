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

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d,e;
        scanf("%d %d %d",&a,&b,&c);
        vector<int> xCoord;
        vector<int> yCoord;
        int n = c;
        while(c--){
            scanf("%d %d",&d,&e);
            xCoord.push_back(d);
            yCoord.push_back(e);
        }
        // greedy, choose median to minimize error
        sort(xCoord.begin(),xCoord.end());
        sort(yCoord.begin(),yCoord.end());
        n -= (n%2 == 0);
        printf("(Street: %d, Avenue: %d)\n",xCoord[n/2],yCoord[n/2]);
    }
}
