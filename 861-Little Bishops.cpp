#include <bits/stdc++.h>
using namespace std;

// precompute result

int ans;
int n,k;

vector<vector<int>> precomputation = {
{1, 1, 0},
{1, 4, 4, 0, 0},
{1, 9, 26, 26, 8, 0, 0},
{1, 16, 92, 232, 260, 112, 16, 0, 0},
{1, 25, 240, 1124, 2728, 3368, 1960, 440, 32, 0, 0},
{1, 36, 520, 3896, 16428, 39680, 53744, 38368, 12944, 1600, 64, 0, 0},
{1, 49, 994, 10894, 70792, 282248, 692320, 1022320, 867328, 389312, 81184, 5792, 128, 0, 0},
{1, 64, 1736, 26192, 242856, 1444928, 5599888, 14082528, 22522960, 22057472, 12448832, 3672448, 489536, 20224, 256, 0, 0}
};

void dfs(int row,int col,int cnt,vector<bool>& diag1,vector<bool>& diag2){
    if(cnt == k) {
        ans++;
        return;
    } else if(row == n) {
        return;
    } else if(col == n)
        return dfs(row+1,0,cnt,diag1,diag2);
    // try placing if allow
    if(!diag1[row-col+(n-1)] && !diag2[row+col]){
        diag1[row-col+(n-1)] = diag2[row+col] = true;
        dfs(row,col+1,cnt+1,diag1,diag2);
        diag1[row-col+(n-1)] = diag2[row+col] = false;
    }
    // do not place
    dfs(row,col+1,cnt,diag1,diag2);
}

int main()
{
    bool precomputed = true;
    while(scanf("%d %d",&n,&k),n||k){
        ans = 0;
        if(!precomputed) {
            vector<bool> diag1(n);
            vector<bool> diag2(2*n);
            dfs(0,0,0,diag1,diag2);
        } else ans = k>2*n ? 0 : precomputation[n-1][k];
        cout << ans << endl;
    }
}
