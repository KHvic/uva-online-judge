#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,m,n,q;
    int a,b;
    char grid[101][101];
    cin >> t;
    while(t--){
        cin >> m >> n >> q;
        for(int i=0;i<m;i++) scanf("%s",grid[i]);

        printf("%d %d %d\n",m,n,q);
        while(q--){
            cin >> a >> b;
            bool valid = true;
            int len = 3,res=1;
            char cur = grid[a][b];
            while(valid){
                int rowStart = a-len/2;
                int rowEnd = a+len/2;
                int colStart = b-len/2;
                int colEnd = b+len/2;
                if(rowStart < 0 || colStart < 0) valid = false;
                if(rowEnd >= m || colEnd >= n) valid = false;
                for(int i=rowStart; i<=rowEnd && valid; i++){
                    if(grid[i][colStart] != cur) valid = false;
                    if(grid[i][colEnd] != cur) valid = false;
                }
                for(int i=colStart; i<=colEnd && valid; i++){
                    if(grid[rowStart][i] != cur) valid = false;
                    if(grid[rowEnd][i] != cur) valid = false;
                }
                if(valid) res = len;
                len += 2;
            }
            cout << res << endl;
        }
    }
}
