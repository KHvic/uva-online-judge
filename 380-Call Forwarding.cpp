#include <bits/stdc++.h>

using namespace std;

int dfs(int source, int time,
         unordered_map<int,map<int,pair<int,int>>>& forwards,
         unordered_set<int>& visited){
    if(visited.count(source)) return 9999;
    visited.insert(source);
    // exact time
    if(forwards[source].count(time)){
        return dfs(forwards[source][time].second,time,forwards,visited);
    }
    auto it = forwards[source].lower_bound(time);
    if(it != forwards[source].begin()){
        // floor
        --it;
        if(it->first + (it->second).first >= time)
            return dfs((it->second).second,time,forwards,visited);
    }
    return source;
}

int main()
{
    int n;
    int s,t,d,e;
    cin >> n;
    cout << "CALL FORWARDING OUTPUT" << endl;
    int tc = 1;
    while(n--){
        unordered_map<int,map<int,pair<int,int>>> forwards;
        while(cin >> s, s){
            cin >> t >> d >> e;
            forwards[s][t] = {d,e};
        }
        printf("SYSTEM %d\n",tc++);
        while(cin >> t, t != 9000){
            cin >> s;
            unordered_set<int> visited;
            int res = dfs(s,t,forwards,visited);
            printf("AT %04d CALL TO %04d RINGS %04d\n",t,s,res);
        }
    }
    printf("END OF OUTPUT\n");
}
