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

struct team {
    string name;
    int points, gplayed, scored, suffered,index;
    team(string n,int i){
        name = n;
        index = i;
        points = gplayed = scored = suffered = 0;
    }
};

int main() {
    int t,g;
    string in;
    string hteam, ateam;
    int s1,s2;
    bool notfirst = false;
    while(scanf("%d %d",&t,&g),t){
        if(notfirst) cout<<endl;
        notfirst = true;
        unordered_map<string,team*> teams;
        for(int i=0;i<t;i++){
            cin >> in;
            team* n = new team(in,i);
            teams[in] = n;
        }
        for(int i=0;i<g;i++){
            cin >> hteam >> s1 >> in >> s2 >> ateam;
            team* team1 = teams[hteam];
            team* team2 = teams[ateam];
            team1->gplayed ++; team2->gplayed++;
            team1->scored += s1; team2->scored += s2;
            team1->suffered += s2; team2->suffered += s1;
            if(s1 == s2) {team1->points++, team2->points++;}
            else if(s1 > s2) team1->points+=3;
            else team2->points+=3;
        }
        vector<team*> res;
        for(auto& p : teams) res.push_back(p.second);
        sort(res.begin(), res.end(), [](team* a,team* b){
             if(a->points != b->points) return a->points > b->points;
             int gd1 = a->scored - a->suffered;
             int gd2 = b->scored - b->suffered;
             if(gd1 != gd2) return gd1 > gd2;
             if(a->scored != b->scored) return a->scored > b->scored;
             string nameA = a->name;
             string nameB = b->name;
             transform(nameA.begin(), nameA.end(), nameA.begin(), ::tolower);
             transform(nameB.begin(), nameB.end(), nameB.begin(), ::tolower);
             if(nameA == nameB) return a->index < b->index;
             return nameA < nameB;
        });
        for(int i=0;i<res.size();i++){
            int gd = res[i]->scored-res[i]->suffered;
            double percentScore = (res[i]->points*100.0) / (res[i]->gplayed*3.0);
            bool sameAsPrevPosition = (i != 0 &&
             (res[i]->points == res[i-1]->points && res[i]->scored == res[i-1]->scored
              && gd == res[i-1]->scored-res[i-1]->suffered));
            cout << setw(3) << (sameAsPrevPosition ? "" : to_string(i+1) + ".");
            cout << setw(16) << res[i]->name << setw(4) << res[i]->points;
            cout << setw(4) << res[i]->gplayed << setw(4) << res[i]->scored;
            cout << setw(4) << res[i]->suffered << setw(4) << gd;
            // property of Nan is that self comparison is always false
            if(percentScore != percentScore) cout << setw(7) << "N/A" << endl;
            else cout << setw(7) << setprecision(2) << fixed << percentScore << endl;
        }
    }
}
