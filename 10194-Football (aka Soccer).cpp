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

struct team{
    string name;
    int gplayed, wins, ties, loses, gscored, gagainst, points, games, gd;
    team(string n){
        name = n;
        gplayed = wins = ties = loses = gscored = gagainst = points = games = gd = 0;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string tname;
        string pname, pname2;
        string in;
        getline(cin,tname);
        int tnum, gnum, a, b;
        unordered_map<string,team*> teamMap;
        cin >> tnum;
        cin.ignore();
        while(tnum--){
            getline(cin,pname);
            team* newT = new team(pname);
            teamMap[pname] = newT;
        }
        cin >> gnum;
        cin.ignore();
        while(gnum--){
            getline(cin,in);
            istringstream iss(in);
            getline(iss,pname,'#');
            getline(iss,in,'@');
            a = stoi(in);
            getline(iss,in,'#');
            b = stoi(in);
            getline(iss,pname2);
            teamMap[pname]->gscored += a;
            teamMap[pname]->gagainst += b;
            teamMap[pname2]->gscored += b;
            teamMap[pname2]->gagainst += a;
            if(a == b){
                teamMap[pname]->ties +=1;
                teamMap[pname2]->ties +=1;
             } else if(a > b){
                teamMap[pname]->wins++;
                teamMap[pname2]->loses++;
             } else {
                ++teamMap[pname]->loses;
                ++teamMap[pname2]->wins;
             }
        }
        vector<team*> res;
        for(auto& p : teamMap) {
            p.second->games = p.second->ties + p.second->wins + p.second->loses;
            p.second->points = p.second->wins*3 + p.second->ties;
            p.second->gd = p.second->gscored - p.second->gagainst;
            res.push_back(p.second);
        }
        sort(res.begin(), res.end(), [](team* a, team* b){
            if(a->points != b->points) return a->points > b->points;
            if(a->wins != b->wins) return a->wins > b->wins;
            if(a->gd != b->gd) return a->gd > b->gd;
            if(a->gscored != b->gscored) return a->gscored > b->gscored;
            if(a->games != b->games) return a->games < b->games;
            string a_name = a->name;
            string b_name = b->name;
            transform(a_name.begin(),a_name.end(),a_name.begin(),::tolower);
            transform(b_name.begin(),b_name.end(),b_name.begin(),::tolower);
            return a_name < b_name;
        });
        cout << tname << endl;
        int i=1;
        for(auto it=res.begin(); it!=res.end(); it++){
            cout<< i++ << ") " << (*it)->name;
            printf(" %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                   (*it)->points, (*it)->games, (*it)->wins, (*it)->ties, (*it)->loses,
                   (*it)->gd, (*it)->gscored, (*it)->gagainst
                   );
        }
        if(n) cout << endl;
    }
}
