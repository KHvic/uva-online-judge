#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,w;

vector<tuple<int,int,int>> edgeList;
vector<int> parent, ranking;

int ufFind(int n){
    return parent[n] == n ? n : parent[n] = ufFind(parent[n]);
}

void join(int v1,int v2){
    int parA = ufFind(v1), parB = ufFind(v2);
    if(ranking[parA] > ranking[parB]) parent[parB] = parA;
    else {
        parent[parA] = parB;
        if(ranking[parA] == ranking[parB]) ranking[parB]++;
    }
}

bool connected(int v1,int v2){
    return ufFind(v1) == ufFind(v2);
}

int main()
{
    // kruskal algorithm
    while(scanf("%d %d",&m,&n),(m+n)!=0){
        edgeList.clear();
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&a,&b,&w);
            edgeList.push_back(make_tuple(w,a,b));
        }
        sort(edgeList.begin(),edgeList.end());

        parent.clear();
        ranking.clear();
        for(int i=0;i<m;i++){
            parent.push_back(i);
            ranking.push_back(0);
        }

        vector<int> res;
        for(auto& t : edgeList)
        if(!connected(get<1>(t),get<2>(t))){
            join(get<1>(t),get<2>(t));
        } else
            res.push_back(get<0>(t));
        if(res.empty()) printf("forest\n");
        else {
            for(auto& w : res){
                printf("%d",w);
                if(&w == &res.back()) printf("\n");
                else printf(" ");
            }
        }
    }
}
