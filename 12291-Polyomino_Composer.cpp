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
    ofstream myfile;
    myfile.open("output.txt");
    int a,b;
    char c;
    while(scanf("%d %d",&a,&b),a){
        vector<pair<int,int> > large;
        vector<pair<int,int> > small;
        unordered_set<int> exist;
        for(int i=0;i<a;i++)
        for(int j=0;j<a;j++){
            cin >> c;
            if(c == '*'){
                large.push_back({i,j});
                exist.insert(i*a+j);
            }
        }
        for(int i=0;i<b;i++)
        for(int j=0;j<b;j++){
            cin >> c;
            if(c == '*') small.push_back({i,j});
        }
        // normalize small coordinates
        pair<int,int> initial = small.front();
        for(auto& p : small){
            p.first -= initial.first;
            p.second -= initial.second;
        }
        bool possible = true;
        if(large.size() != small.size()*2){
            possible = false;
        }
        for(int i=0;i<2&&possible;i++){
            pair<int,int> topLeft = {0,0};
            possible = false;
            for(auto& p : large)
                if(exist.find(p.first*a+p.second) != exist.end()){
                    topLeft = p;
                    possible = true;
                    break;
                }
            for(auto it=small.begin();it!=small.end() && possible; it++){
                pair<int,int> translatedCoord = {it->first+topLeft.first, it->second+topLeft.second};
                if(translatedCoord.first < 0 || translatedCoord.second < 0){
                    possible = false;
                    break;
                }
                int coordId = translatedCoord.first*a+translatedCoord.second;
                if(exist.count(coordId)){
                    exist.erase(coordId);
                } else {
                    possible = false;
                }
            }
        }
        myfile << (possible ? 1 : 0) << endl;
    }
}
