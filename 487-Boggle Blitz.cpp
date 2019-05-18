#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
auto cmp = [](const string& a,const string& b){
    if(a.length() == b.length()) return a<b;
    else return a.length() < b.length();
};
set<string,decltype(cmp)> res(cmp);

void dfs(int r,int c,string& cur,vector<string> grid){
    if(r<0||c<0||r>=grid.size()||c>=grid.size()) return;
    if(!cur.empty() && grid[r][c] <= cur.back()) return;
    cur += grid[r][c];
    if(cur.length() > 2) res.insert(cur);
    for(auto& dir : dirs){
        int x = r+dir[0];
        int y = c+dir[1];
        dfs(x,y,cur,grid);
    }
    cur.pop_back();
}

int main()
{
    int t,n;
    string in;
    cin >> t;
    while(t--){
        vector<string> grid;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> in;
            grid.push_back(in);
        }
        res.clear();
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            string cur = "";
            dfs(i,j,cur,grid);
        }
        for(auto& word : res)
            cout << word << endl;
        if(t) cout << endl;
    }
}
