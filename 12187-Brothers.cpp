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

void battle(vector<vector<int> >& g,int n){
    vector<vector<int> > next(g);
    int rowSize = g.size();
    int colSize = g[0].size();
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            int opp = (g[i][j]+1) % n;
            if(i!=0 && g[i-1][j] == opp)
                next[i-1][j] = g[i][j];
            if(i+1!=rowSize &&  g[i+1][j] == opp)
                next[i+1][j] = g[i][j];
            if(j!=0 && g[i][j-1] == opp)
                next[i][j-1] = g[i][j];
            if(j+1!=colSize && g[i][j+1] == opp)
                next[i][j+1] = g[i][j];
        }
    }
    g = next;
}

int main(){
    int n,r,c,k;
    while(scanf("%d %d %d %d",&n,&r,&c,&k),n){
        vector<vector<int> > g(r,vector<int>(c));
        int v;
        for(int i=0;i<r;i++) for(int j=0;j<c;j++){
            cin >> v;
            g[i][j] = v;
        }
        while(k--){
            battle(g,n);
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++){
                cout << g[i][j] << (j+1 == c ? "\n" : " ");
            }
        }
    }
}
