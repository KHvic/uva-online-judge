#include <bits/stdc++.h>

//  complete search between 2 coord O(O*T), nums of one and three
using namespace std;

int main()
{
    int M;
    char cells[101][101];

    while(scanf("%d",&M) != EOF){
        for(int i=0;i<M;i++) scanf("%s",cells[i]);

        vector<pair<int,int>> ones;
        vector<pair<int,int>> threes;

        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                if(cells[i][j]=='1'){
                    ones.push_back({i,j});
                }else if(cells[i][j]=='3'){
                    threes.push_back({i,j});
                }

        int res = INT_MIN;

        for(auto& p1 : ones){
            int best = INT_MAX;
            for(auto& p2 : threes)
                best = min(best,abs(p1.first-p2.first)+abs(p1.first-p2.second));
            res = max(best,res);
        }

        printf("%d\n",res);
    }

    return 0;
}
