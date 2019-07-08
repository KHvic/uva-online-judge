#include <bits/stdc++.h>
using namespace std;

int main()
{
  int r,c,b,rn,bn,cn;
  int sx,sy,ex,ey;
  vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
  while(scanf("%d %d",&r,&c), (r+c)!=0){
      scanf("%d",&b);
      vector<vector<bool>> graph(r, vector<bool>(c));
      for(int i=0;i<b;i++){
          scanf("%d %d",&rn,&bn);
          for(int j=0;j<bn;j++){
            scanf("%d",&cn);
            graph[rn][cn] = true;
          }
      }
      scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
      queue<pair<int,int>> q;
      q.push({sx,sy});
      int steps = 0;
      bool found = false;
      while(!q.empty() && !found){
          int len = q.size();
          for(int i=0;i<len;i++){
              int x,y;
              tie(x,y) = q.front(); q.pop();
              if(x == ex && y == ey) {
                  found = true;
                  break;
              }
              for(auto& dir : dirs){
                  int nextX = x+dir[0];
                  int nextY = y+dir[1];
                  if(nextX<0||nextY<0||nextX>=r||nextY>=c) continue;
                  if(graph[nextX][nextY]) continue;
                  q.push({nextX,nextY});
                  graph[nextX][nextY] = true; // mark visited
              }
          }
          if(!found) steps++;
      }
      printf("%d\n",steps);
  }
}
