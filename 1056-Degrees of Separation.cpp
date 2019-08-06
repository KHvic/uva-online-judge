#include <bits/stdc++.h>

using namespace std;

// 2 solutions: floyd warshall or double dfs

int main()
{
    int n,e,tc=1;
    string a,b;
    while(scanf("%d %d",&n,&e),(n+e)!=0){
        unordered_map<string,int> idxMap;
        vector<vector<int>> dist(n,vector<int>(n,1e6));
        int idx=0;
        for(int i=0;i<e;i++){
            cin >> a >> b;
            if(!idxMap.count(a)) idxMap[a] = idx++;
            if(!idxMap.count(b)) idxMap[b] = idx++;
            dist[idxMap[a]][idxMap[b]] = 1;
            dist[idxMap[b]][idxMap[a]] = 1;
        }

        for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        
        int diameter = 0;
        bool disconnected = false;
        for(int i=0;i<n&&!disconnected;i++){
            for(int j=0;j<n&&!disconnected;j++){
                if(i!=j){
                    diameter = max(dist[i][j],diameter);
                    if(dist[i][j] == 1e6) disconnected = true;
                }
            }
        }
        printf("Network %d: ",tc++);
        if(disconnected) printf("DISCONNECTED\n\n");
        else printf("%d\n\n",diameter);
    }
}
