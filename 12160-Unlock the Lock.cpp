#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,u,r,v,tc=1;
    while(scanf("%d %d %d",&l,&u,&r),(l+u+r)!=0){
        vector<int> rv;
        for(int i=0;i<r;i++){
            scanf("%d",&v);
            rv.push_back(v);
        }
        int steps=0;
        bool found = false;
        unordered_set<int> visited;
        visited.insert(l);
        queue<int> bfs;
        bfs.push(l);
        while(!found && !bfs.empty()){
            int len = bfs.size();
            for(int i=0;i<len && !found;i++){
                int cur = bfs.front(); bfs.pop();
                if(cur == u) found = true;
                for(auto& add : rv){
                    int nextVal = (cur+add) % 10000;
                    if(!visited.count(nextVal)){
                        visited.insert(nextVal);
                        bfs.push(nextVal);
                    }
                }
            }
            if(!found) steps++;
        }
        printf("Case %d: ",tc++);
        if(found) printf("%d\n",steps);
        else printf("Permanently Locked\n");
    }
}
