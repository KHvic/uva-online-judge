#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    while(getline(cin,in),in != "#"){
        istringstream iss(in);
        unordered_map<char,unordered_set<char>> graph;
        unordered_set<char> characters;
        while(getline(iss,in,';')){
            char n = in[0];
            characters.insert(n);
            string neighs = in.substr(in.find(":")+1);
            for(auto& c : neighs) {
                graph[n].insert(c);
                characters.insert(c);
            }
        }

        int best = INT_MAX;
        string bestOrder = "";
        string cur = "";
        for(auto& c : characters) cur+=c;
        sort(cur.begin(),cur.end());

        do{
            vector<int> charPos(26);
            for(int i=0;i<cur.size();i++) charPos[cur[i]-'A'] = i;
            int maxBandwidth = 1;
            for(int i=0;i<cur.size();i++){
                char n = cur[i];
                for(auto& neigh : graph[n])
                    maxBandwidth = max(abs(i-charPos[neigh-'A']), maxBandwidth);
            }
            if(maxBandwidth < best){
                best = maxBandwidth;
                bestOrder = cur;
            }
        } while(next_permutation(cur.begin(),cur.end()));
        for(auto& c : bestOrder){
            cout << c << " ";
        }
        cout << "-> " << best << endl;
    }
}
