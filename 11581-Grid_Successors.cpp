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

bool f(vector<vector<int> >& m){
    vector<vector<int> > m2(3,vector<int>(3));
    bool hasOne = false;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int sum = 0;
            if(i!=0) sum += m[i-1][j];
            if(i!=2) sum += m[i+1][j];
            if(j!=0) sum += m[i][j-1];
            if(j!=2) sum += m[i][j+1];
            m2[i][j] = sum % 2;
            if(m2[i][j]) hasOne = true;
        }
    }
    swap(m2,m);
    return hasOne;
}


int main(){
    int t;
    scanf("%d",&t);
    int k = 1;
    while(t--){
        vector<vector<int> > m(3,vector<int>(3));
        bool hasOne = false;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                scanf("%1d",&k);
                m[i][j] = k;
                if(m[i][j]) hasOne = true;
            }
        }
        int res = -1;
        while(hasOne){
            res++;
            hasOne = f(m);
        }
        cout << res << endl;
    }
}
