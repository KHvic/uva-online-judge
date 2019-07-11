#include <bits/stdc++.h>

using namespace std;
int dfs_counter,num_SCC;
vector<vector<int>> graph;
vector<bool> instack;
vector<int> dfs_num, dfs_low;
stack<int> st;

void tarjanSCC(int u){
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    st.push(u);
    instack[u] = true;
    for(int neigh : graph[u]){
        if(dfs_num[neigh] == -1){
            tarjanSCC(neigh);
        }
        if(instack[neigh]) 
            dfs_low[u] = min(dfs_low[u], dfs_low[neigh]);
    }
    if(dfs_num[u] == dfs_low[u]){
        num_SCC++;
        while(true){
            int top = st.top(); st.pop();
            instack[top] = false;
            if(top == u) break;
        }
    }
}

int main()
{
   int n,m,a,b,p;
   while(scanf("%d %d",&n,&m),(n+m)!=0){
       graph.assign(n,vector<int>());
       instack.assign(n,false);
       dfs_low.assign(n,-1);
       dfs_num.assign(n,-1);
       dfs_counter = num_SCC = 0;
       for(int i=0;i<m;i++){
           scanf("%d %d %d",&a,&b,&p);
           a--; b--;
           graph[a].push_back(b);
           if(p==2) graph[b].push_back(a);
       }
      for(int i=0;i<n;i++)
            if(dfs_num[i] == -1)
                tarjanSCC(i);
       printf("%d\n", num_SCC == 1 ? 1 : 0);
   }
}
