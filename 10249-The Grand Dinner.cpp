#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n,v;
    while(scanf("%d %d",&m,&n),m){
        priority_queue<pair<int,int>> tables;
        vector<pair<int,int>> teams;
        vector<vector<int>> res(m);
        for(int i=0;i<m;i++){
            cin >> v;
            teams.push_back({v,i});
        }
        sort(teams.begin(),teams.end(),greater<pair<int,int>>());
        for(int i=0;i<n;i++){
            cin >> v;
            tables.push({v,i});
        }
        bool valid = true;
        for(int i=0;i<teams.size() && valid;i++){
            int teamSize = teams[i].first;
            // get top k tables
            if(tables.size() < teamSize) valid = false;
            else {
                vector<pair<int,int>> usedTables;
                vector<int> team;
                for(int j=0;j<teamSize;j++){
                    pair<int,int> table = tables.top();tables.pop();
                    team.push_back(table.second+1);
                    if(--table.first)
                        usedTables.push_back(table);
                }
                res[teams[i].second] = team;
                for(auto& p : usedTables) tables.push(p);
            }
        }
        if(valid){
            printf("1\n");
            for(auto& team : res){
                for(auto& seat : team){
                    cout << seat;
                    if(&seat == &team.back()) cout << endl;
                    else cout << " ";
                }
            }
        } else {
            printf("0\n");
        }
    }
}
