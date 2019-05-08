#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,v;
    while(cin >> t){
        vector<vector<bool>> graph;
        for(int i=0;i<t;i++){
            vector<bool> edges;
            for(int j=0;j<t;j++){
                cin >> v;
                edges.push_back(v == 0 ? false : true);
            }
            graph.push_back(edges);
        }
        int res = 0;
        vector<tuple<int,int,int>> descendRes;
        for(int i=0;i<t;i++){
            for(int j=i+1;j<t;j++){
                if(!graph[i][j] && !graph[j][i]) continue;
                for(int k=j+1;k<t;k++){
                    if(graph[i][j] && graph[j][k] && graph[k][i]){
                        res++;
                        descendRes.push_back(make_tuple(i+1,j+1,k+1));
                    }
                    if(graph[k][j] && graph[j][i] && graph[i][k]){
                        res++;
                        descendRes.push_back(make_tuple(k+1,j+1,i+1));
                    }
                }
            }
        }
        sort(descendRes.begin(),descendRes.end());
        for(auto& s : descendRes) printf("%d %d %d\n",get<0>(s),get<1>(s),get<2>(s));
        printf("total:%d\n\n",res);
    }
}
