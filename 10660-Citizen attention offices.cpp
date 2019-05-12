#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,v;
    int x,y,s;
    cin >> t;
    while(t--){
        cin >> n;
        vector<tuple<int,int,int>> pops;
        for(int i=0;i<n;i++){
            cin >> x >> y >> s;
            pops.push_back(make_tuple(x,y,s));
        }
        int best = INT_MAX;
        vector<int> bestRes;
        // for each office combination, compute cost
        for(int i=0;i<25;i++){
            for(int j=i+1;j<25;j++){
                for(int k=j+1;k<25;k++){
                    for(int l=k+1;l<25;l++){
                        for(int m=l+1;m<25;m++){
                            int cost = 0;
                            for(auto& t : pops){
                                int minCost = INT_MAX;
                                for(int office : {i,j,k,l,m}){
                                    minCost = min(abs(office/5-get<0>(t))+abs(office%5-get<1>(t)),minCost);
                                }
                                cost += (minCost*get<2>(t));
                            }
                            if(cost < best){
                                best = cost;
                                bestRes = {i,j,k,l,m};
                            }
                        }
                    }
                }
            }
        }
        printf("%d %d %d %d %d\n",bestRes[0],bestRes[1],bestRes[2],bestRes[3],bestRes[4]);
    }
}
