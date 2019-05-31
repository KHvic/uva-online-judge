#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,c,tc=1;
    while(scanf("%d",&n),n){
        vector<tuple<int,int,int>> blocks;
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&a,&b,&c);
            blocks.push_back(make_tuple(a,b,c));
            blocks.push_back(make_tuple(a,c,b));
            blocks.push_back(make_tuple(b,a,c));
            blocks.push_back(make_tuple(b,c,a));
            blocks.push_back(make_tuple(c,a,b));
            blocks.push_back(make_tuple(c,b,a));
        }
        sort(blocks.begin(),blocks.end(),greater<tuple<int,int,int>>());
        vector<int> dp(blocks.size());
        int best = 0;
        for(int i=0;i<blocks.size();i++){
            for(int j=0;j<i;j++){
                if(get<0>(blocks[i]) < get<0>(blocks[j]) &&
                   get<1>(blocks[i]) < get<1>(blocks[j])){
                    dp[i] = max(dp[i],dp[j]);
                   }
            }
            dp[i] += get<2>(blocks[i]);
            best = max(dp[i],best);
        }
        printf("Case %d: maximum height = %d\n",tc++,best);
    }
}
