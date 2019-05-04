#include <bits/stdc++.h>
using namespace std;

int main() {
    int b[3];
    int g[3];
    int c[3];
    while(scanf("%d %d %d %d %d %d %d %d %d",
                b,g,c,b+1,g+1,c+1,b+2,g+2,c+2) != EOF){
        string cur = "BCG";
        string best = "ZZZ";
        int bestCnt = INT_MAX;
        // BCG
        do{
            int cost = 0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i==j) continue;
                    if(cur[i] == 'B') cost += b[j];
                    else if(cur[i] == 'C') cost += c[j];
                    else if(cur[i] == 'G') cost += g[j];
                }
            }
            if(cost < bestCnt) {
                bestCnt = cost;
                best = cur;
            }
        }while(next_permutation(cur.begin(),cur.end()));

        cout << best << " " << bestCnt << endl;
    }
}
