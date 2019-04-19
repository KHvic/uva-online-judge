#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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

struct team{
    int num, solved, time;
    team(int t){
        num = t;
        solved = time = 0;
    }
};

int main() {
    int cases;
    scanf("%d\n",&cases);
    int t, mins;
    string time, in;
    char status, problem;
    while(cases--){
        unordered_map<int,team*> tMap;
        unordered_map<int,unordered_map<char,vector<pair<int,bool>>>> probMap;
        int maxTeam = 0;
        while(getline(cin,in), !in.empty()){
            istringstream iss(in);
            iss >> t >> problem >> time >> status;
            maxTeam = max(maxTeam, t);
            if(tMap.count(t) == 0){
                team* n = new team(t);
                tMap[t] = n;
                probMap[t] = unordered_map<char,vector<pair<int,bool>>>();
            }
            if(probMap[t].count(problem) == 0){
                probMap[t][problem] = vector<pair<int,bool>>();
            }
            int delimit = time.find(":");
            mins = stoi(time.substr(0,delimit))*60 + stoi(time.substr(delimit+1));
            probMap[t][problem].push_back({mins, status == 'Y'});
        }
        for(auto& p : tMap){
            auto& pList = probMap[p.first];
            team* cur = p.second;
            for(auto& record : pList){
                // sort by submission time
                sort(record.second.begin(), record.second.end());
                int totalTime = 0;
                for(auto& submission : record.second){
                    // add time if completed and ignore remaining submission
                    if(submission.second) {
                        totalTime += submission.first;
                        cur->solved++;
                        cur->time += totalTime;
                        break;
                    } else totalTime += 20;
                }
            }
        }
        vector<team*> res;
        for(int i=1;i<=maxTeam;i++) if(tMap.count(i) == 0){
            res.push_back(new team(i));
        }
        for(auto& p : tMap) res.push_back(p.second);
        sort(res.begin(), res.end(), [](team* a, team* b){
             if(a->solved != b->solved) return a->solved > b->solved;
             if(a->time != b->time) return a->time < b->time;
             return a->num < b->num;
             });
        cout << "RANK TEAM PRO/SOLVED TIME\n";
        int ranking = 1;
        for(int i=0;i<res.size();i++){
            if(i!=0 && (res[i]->solved != res[i-1]->solved || res[i]->time != res[i-1]->time))
                ranking = i+1;
            cout << setw(4) << ranking << " ";
            cout << setw(4) << res[i]->num;
            if(res[i]->solved){
                cout << " " << setw(4) << res[i]->solved << "       ";
                cout << setw(4) << res[i]->time << endl;
            } else cout << endl;
        }
        if(cases) cout << endl;
    }
}
