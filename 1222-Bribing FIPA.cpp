#include <bits/stdc++.h>
using namespace std;

// tree dp: solve for child first, then solve for parent using child info

map<string, int> cIdx;
int highestIdx = 1;
vector<int> price;
vector<int> tree_size;
vector<int> indegree;
vector<vector<int>> graph;
string in, v, v2;
int p, n, m;
int memo[201][201]; // state: tree, valueLeft

int getIdx(string c) {
    if(!cIdx.count(c)) cIdx[c] = highestIdx++;
    return cIdx[c];
}

// perform btm up dp on parent to child
void solve(int cur) {
    memo[cur][0] = 0;
    for(auto& child : graph[cur]) {
        solve(child);
        // variation of knapsack problem, where child cannot be reused
        for(int target=m;target>0;target--){ // update larger value first to not pollute smaller value (single usage)
            for(int i=0;i<=target;i++){
                memo[cur][target] = min(memo[cur][target], memo[child][i] + memo[cur][target-i]);
            }
        }
    }
    for(int i=0;i<=tree_size[cur];i++){
        memo[cur][i] = min(memo[cur][i], price[cur]);
    }
}

int dfsSum(int cur) {
    int sum = 1;
    for(auto& c : graph[cur])
        sum += dfsSum(c);
    return tree_size[cur] = sum;
}

int main() {
    while(getline(cin, in), in != "#") {
        istringstream iss2(in);
        iss2 >> n >> m;
        cIdx.clear();
        price.assign(n+1,1e7);
        tree_size.assign(n+1, 0);
        graph.assign(n+1,vector<int>());
        indegree.assign(n+1,0);
        highestIdx = 1;
        for(int i=0;i<n;i++){
            getline(cin, in);
            istringstream iss(in);
            iss >> v >> p;
            int pIdx = getIdx(v);
            price[pIdx] = p;
            while(iss >> v2) {
                int cIdx = getIdx(v2);
                indegree[cIdx]++;
                graph[pIdx].push_back(cIdx);
            }
        }
        // connect all components into a tree
        for(int i=1;i<graph.size();i++)
            if(indegree[i] == 0){
                graph[0].push_back(i);
            }
        memset(memo, 0x3f, sizeof memo);
        dfsSum(0);
        solve(0);
        printf("%d\n", memo[0][m]);
    }
}
