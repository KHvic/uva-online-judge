#include <bits/stdc++.h>
using namespace std;

int compute(int i,int j,vector<vector<int>>& memo,vector<vector<string>>& sheet)
{
    if(sheet[i][j].empty()) return memo[i][j];
    istringstream iss(sheet[i][j]);
    string cell;
    int total = 0;
    while(getline(iss,cell,'+')){
        int idx=0;
        int col=0;
        while(isalpha(cell[idx])){
            col *= 26;
            col += (cell[idx] - 'A'+1);
            idx++;
        }
        col--;
        int row = stoi(cell.substr(idx))-1;
        total += compute(row,col,memo,sheet);
    }
    sheet[i][j].clear();
    return memo[i][j] = total;
}

int main()
{
    int t,m,n;
    string in;
    cin >> t;
    while(t--){
        cin >> m >> n;
        vector<vector<int>> memo(n,vector<int>(m,-1));
        vector<vector<string>> sheet(n,vector<string>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> in;
                if(in[0] == '=') sheet[i][j] = in.substr(1);
                else memo[i][j] = stoi(in);
            }
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            printf("%d",compute(i,j,memo,sheet));
            if(j==m-1) printf("\n");
            else printf(" ");
        }
    }
}
