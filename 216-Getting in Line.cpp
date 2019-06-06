#include <bits/stdc++.h>
using namespace std;
int n,x,y;
vector<pair<int,int>> computers;
double memo[1<<8][8];
double decision[1<<8][8];

double euclidean(int i, int j){
    x = computers[i].first-computers[j].first;
    y = computers[i].second-computers[j].second;
    return sqrt(x*x + y*y);
}

double tsp(int pos, int bitmask){
    if(bitmask == ((1<<n)-1)) return 0;
    if(memo[bitmask][pos] >= 0) return memo[bitmask][pos];
    double res = 1e8;
    for(int i=0;i<n;i++)
    if(!(bitmask & (1<<i))){
        double cost = tsp(i,bitmask | (1<<i)) + euclidean(pos,i);
        if(cost < res){
            res = cost;
            decision[bitmask][pos] = i;
        }
    }
    return memo[bitmask][pos] = res;
}

int main()
{
    int tc=1;
    while(scanf("%d",&n),n){
        computers.clear();
        memset(memo,-1,sizeof memo);
        memset(decision,-1,sizeof decision);
        for(int i=0;i<n;i++){
            cin >> x >> y;
            computers.push_back({x,y});
        }
        printf("**********************************************************\n");
        printf("Network #%d\n",tc++);
        double best = 1e8;
        int bestStart = 0;
        for(int i=0;i<n;i++){
            double cost = tsp(i,1<<i);
            if(cost < best){
                best = cost;
                bestStart = i;
            }
        }
        int cur = bestStart;
        int curState = 1<<bestStart;
        double totalFeet = 0;
        while(curState != ((1<<n)-1)){
            int x1,x2,y1,y2;
            int nxt = decision[curState][cur];
            tie(x1,y1) = computers[cur];
            tie(x2,y2) = computers[nxt];
            double dist = euclidean(cur,nxt)+16.0;
            totalFeet += dist;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",x1,y1,x2,y2,dist);
            curState ^= 1<<nxt;
            cur = nxt;
        }
        printf("Number of feet of cable required is %.2f.\n",totalFeet);
    }
}
