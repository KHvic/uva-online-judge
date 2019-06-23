#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,r,a,b,t,tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&r);
        vector<pair<int,int>> cities;
        for(int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            cities.push_back({a,b});
        }

        int state = 1;
        double road=0, rail=0;
        // prim algorithm
        vector<bool> taken(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            int cur,dist;
            tie(dist,cur) = pq.top(); pq.pop();
            if(taken[cur]) continue;
            if(sqrt(dist) > r){
                rail += sqrt(dist);
                state++;
            } else {
                road += sqrt(dist);
            }
            taken[cur] = true;
            bool allTaken = true;
            for(int i=0;i<n;i++){
                if(!taken[i]){
                    allTaken = false;
                    // compute euclidean dist
                    int xDiff = cities[i].first - cities[cur].first;
                    int yDiff = cities[i].second - cities[cur].second;
                    xDiff*=xDiff;
                    yDiff*=yDiff;
                    pq.push({xDiff+yDiff,i});
                }
            }
            if(allTaken) break;
        }
        printf("Case #%d: %d %.0f %.0f\n",tc++,state,road,rail);
    }
}
