#include <bits/stdc++.h>
using namespace std;

int N, target;
double dist[20][20], memo[1 << 16];  // 1 << 16 = 2^16, note that max N = 8

// O(N*2^(2N))
double matching(int bitmask) {
    if (memo[bitmask] > -0.5)
        return memo[bitmask];
    if (bitmask == target)
        return memo[bitmask] = 0;

    double ans = 2000000000.0;
    int p1, p2;
    // find first bit that is not set
    for (p1 = 0; p1 < 2 * N; p1++)
        if (!(bitmask & (1 << p1)))
            break;
    // try all other bit that is not set
    for (p2 = p1 + 1; p2 < 2 * N; p2++)
        if (!(bitmask & (1 << p2)))
          ans = min(ans, dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));

    return memo[bitmask] = ans;
}

int main() {
    int i, j, caseNo = 1, x[20], y[20];
    while (scanf("%d", &N), N) {
        for (i = 0; i < 2 * N; i++)
          scanf("%*s %d %d", &x[i], &y[i]);
        // distance between all pairs
        for (i = 0; i < 2 * N - 1; i++)
          for (j = i + 1; j < 2 * N; j++)
            dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);

        for (i = 0; i < (1 << 16); i++) memo[i] = -1.0;  // set -1 to all cells
        target = (1 << (2 * N)) - 1; // all set
        printf("Case %d: %.2f\n", caseNo++, matching(0));
    }
}
