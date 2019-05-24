#include <bits/stdc++.h>
using namespace std;

int main() {
    int r,c,v,q,l,u;
    while(scanf("%d %d",&r,&c),r||c){
        vector<vector<int>> grid;
        for(int i=0;i<r;i++){
            vector<int> row;
            for(int j=0;j<c;j++){
                cin >> v;
                row.push_back(v);
            }
            grid.push_back(row);
        }
        cin >> q;
        while(q--){
            cin >> l >> u;
            int best = 0;
            for(int row=0;row<grid.size();row++){
                // find first item larger than left interval
                auto left = lower_bound(grid[row].begin(),grid[row].end(),l);
                if(left == grid[row].end()) continue;
                int colStart = left-grid[row].begin();
                // try each square size from current best
                for(int size=best;size<r;size++){
                    int colEnd = colStart+size;
                    int rowEnd = row+size;
                    // out of bound check
                    if(colEnd >= c) break;
                    if(rowEnd >= r) break;
                    if(grid[rowEnd][colEnd] > u) break; // too large
                    best = max(best,size+1);
                }
            }
            cout << best << endl;
        }
        cout << '-' << endl;
    }
}
