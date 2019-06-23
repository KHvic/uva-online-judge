#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,w;

vector<tuple<int,int,int>> edgeList;
vector<int> parent;

int ufFind(int n){
    return parent[n] == n ? n : parent[n] = ufFind(parent[n]);
}

void join(int v1,int v2){
    int parA = ufFind(v1), parB = ufFind(v2);
    parent[parB] = parA;
}

bool connected(int v1,int v2){
    return ufFind(v1) == ufFind(v2);
}

int main()
{
    int t;
    scanf("%d",&t);
    // kruskal algorithm
    while(t--){
        scanf("%d %d",&m,&n);
        edgeList.clear();
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&a,&b,&w);
            edgeList.push_back(make_tuple(w,a-1,b-1));
        }
        sort(edgeList.begin(),edgeList.end(),greater<tuple<int,int,int>>());

        parent.clear();
        for(int i=0;i<m;i++) parent.push_back(i);

        int res = 0;
        for(auto& t : edgeList)
        if(!connected(get<1>(t),get<2>(t))){
            join(get<1>(t),get<2>(t));
        } else
            res += get<0>(t);
        printf("%d\n",res);
    }
    scanf("%d",&t);
}
