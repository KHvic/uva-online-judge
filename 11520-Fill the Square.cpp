#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

int main()
{
    int t,n,tc=1;
    string in;
    cin >> t;
    while(t--){
        vector<string> matrix;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> in;
            matrix.push_back(in);
        }

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(matrix[i][j] == '.'){
            bool valid = false;
            for(char c='A';c<='Z' && !valid;c++){
                valid = true;
                for(auto& dir : dirs){
                    int x = i+dir[0]; int y = j+dir[1];
                    if(x<0||y<0||x>=n||y>=n) continue;
                    if(matrix[x][y] == c) {
                        valid = false; break;
                    }
                }
                if(valid) matrix[i][j] = c;
            }
        }

        printf("Case %d:\n",tc++);
        for(auto& s : matrix)
            cout << s << endl;
    }
}
