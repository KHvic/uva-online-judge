#include <bits/stdc++.h>
using namespace std;

void dfs(const string& child, map<string,string>& gene,
         unordered_map<string,vector<string>>& parents){
    if(gene.count(child)) return;
    vector<string> parent = parents[child];
    dfs(parent[0],gene,parents);
    dfs(parent[1],gene,parents);
    string trait1 = gene[parent[0]], trait2 = gene[parent[1]];
    if(trait1 == "recessive" && trait2 == "recessive")
        gene[child] = "recessive";
    else if(trait1 == "dominant" || trait2 == "dominant"){
        if((trait1 == "dominant" && trait2 == "dominant") ||
           (trait1 == "recessive" || trait2 == "recessive"))
            gene[child] = "dominant";
        else
            gene[child] = "recessive";
    } else
        gene[child] = "non-existent";
}

int main() {
    int p;
    string in1, in2;
    cin >> p;
    map<string,string> gene;
    unordered_map<string,vector<string>> parents;
    while(p--){
        cin >> in1 >> in2;
        if(in2 == "dominant" || in2 == "recessive" || in2 == "non-existent")
            gene[in1] = in2;
        else{
            if(!parents.count(in2)) parents[in2] = vector<string>();
            parents[in2].push_back(in1);
        }
    }
    for(auto& p : parents) dfs(p.first, gene, parents);
    for(auto it=gene.begin();it!=gene.end();it++)
        cout << it->first << " " << it->second << endl;
}
