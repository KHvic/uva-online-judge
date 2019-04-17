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
    string in;
    int id, qId, time;
    char L;
    scanf("%d\n",&t);
    while(t--){
        unordered_map<int, int> penalty_map;
        unordered_map<int, unordered_set<int>> solved_map;
        unordered_map<int, vector<int>> accumulate_map;
        while(getline(cin,in)){
            if(in.empty()) break;
            istringstream iss(in);
            iss >> id >> qId >> time >> L;
            if(!solved_map.count(id)){
                solved_map[id] = unordered_set<int>();
                penalty_map[id] = 0;
                accumulate_map[id] = vector<int>(10,0);
            }
            if(solved_map[id].count(qId)) continue;
            if(L == 'C'){
                penalty_map[id] += time;
                penalty_map[id] += accumulate_map[id][qId];
                solved_map[id].insert(qId);
            } else if(L == 'I'){
                accumulate_map[id][qId] += 20;
            }
        }
        vector<tuple<int,int,int>> res;
        for(auto p : penalty_map){
            res.push_back(make_tuple(p.first, solved_map[p.first].size(), p.second));
        }
        sort(res.begin(),res.end(),[](tuple<int,int,int>& a, tuple<int,int,int>& b){
                if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
                if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
                return get<0>(a) < get<0>(b);
             });

        for(auto& t : res){
            printf("%d %d %d\n",get<0>(t), get<1>(t), get<2>(t));
        }
        if(t) cout << endl;
    }
}
