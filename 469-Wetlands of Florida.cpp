#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
vector<string> grid;
vector<pair<int,int>> visited;

int dfs(int x,int y){
    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].length()) return 0;
    if(grid[x][y] != 'W') return 0;
    int res = 1;
    grid[x][y] = '.'; // mark visited
    visited.push_back({x,y});
    for(auto& dir : dirs){
        int nxtX = x+dir[0];
        int nxtY = y+dir[1];
        res += dfs(nxtX,nxtY);
    }
    return res;
}

int main() {
    int t,x,y;
    string in;
    scanf("%d\n\n",&t);
    while(t--){
        grid.clear();
        unordered_map<string,int> cache;
        while(getline(cin,in), !in.empty()){
            if(isdigit(in[0])){
                istringstream iss(in);
                iss >> x >> y;
                int res;
                string key = to_string(x-1)+":"+to_string(y-1);
                if(cache.count(key))
                    res = cache[key];
                else {
                    visited.clear();
                    res = dfs(x-1,y-1);
                    for(auto& p : visited)
                        cache[to_string(p.first)+":"+to_string(p.second)] = res;
                }
                printf("%d\n",res);
            } else {
                grid.push_back(in);
            }
        }
        if(t) printf("\n");
    }
}
