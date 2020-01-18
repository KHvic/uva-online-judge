#include <bits/stdc++.h>
using namespace std;

// state: remaining for each of the 4 colors, first color, first size, previous color, previous size
int dp[8][8][8][8][4][3][4][3];
int tc,n,v;

int solve(vector<int>& remain, int first_color, int first_size, int prev_color, int prev_size) {
    int total_remain = accumulate(remain.begin(), remain.end(), 0);
    if(total_remain == 0) {
        return (prev_color == first_color || first_size == prev_size) ? 0 : 1;
    }
    int &res = dp[remain[0]][remain[1]][remain[2]][remain[3]][first_color][first_size][prev_color][prev_size];
    if(res != -1) return res;
    res = 0;
    for(int i=0;i<n;i++){
        if(prev_color == i) continue;
        for(int j=0;j<min(3,remain[i]);j++){
            if(prev_size == j) continue;
            remain[i] -= (j+1);
            res += solve(remain, first_color, first_size, i, j);
            remain[i] += (j+1);
        }
    }
    return res;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        vector<int> remain(4,0);
        for(int i=0;i<n;i++) {
            scanf("%d", &remain[i]);
        }
        int res = 0;
        int sum = accumulate(remain.begin(), remain.end(),0);
        if(sum == 0) res = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<min(3,remain[i]);j++){
                remain[i] -= (j+1);
                if(sum - (j+1) > 0)
                    res += solve(remain,i,j,i,j);
                else
                    sum++;
                remain[i] += (j+1);
            }
        }
        printf("%d\n", res);
    }
}
