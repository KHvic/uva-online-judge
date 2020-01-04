#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int T[31][102];
    int Y[31][102];
    int p[31];
    while(scanf("%d %d", &n, &m), n+m) {
        for(int i=0;i<m;i++)
            scanf("%d", p+i);
        memset(T, 0, sizeof T);
        memset(Y, 127, sizeof Y);

        // find max T - safeline of all storage
        for(int i=0;i<m;i++) { // foreach keeper
            T[i][0] = 1e7;
            for(int j=0;j<=n;j++) { // foreach sub-problem size, smaller problems first
                T[i+1][j] = max(T[i+1][j], T[i][j]); // safeline excluding keeper i (0 storage)
                for(int k=1;j+k<=n;k++) { // number of storages handled by keeper i
                    int val = min(T[i][j], p[i]/k); // min safeline including keeper i
                    T[i+1][j+k] = max(T[i+1][j+k], val);
                }
            }
        }
        // find min Y
        int res = T[m][n];
        for(int i=0;i<m;i++) {
            Y[i][0] = 0;
            for(int j=0;j<=n;j++) {
                if(T[i+1][j] >= res)
                    Y[i+1][j] = min(Y[i+1][j], Y[i][j]);
                for(int k=1;j+k<=n;k++) {
                    int val = min(T[i][j], p[i]/k);
                    if(val >= res) // if same T, update Y
                        Y[i+1][j+k] = min(Y[i+1][j+k], Y[i][j]+p[i]);
                }
            }
        }
        if(res == 0) Y[m][n] = 0;
        printf("%d %d\n", res, Y[m][n]);
    }
}
