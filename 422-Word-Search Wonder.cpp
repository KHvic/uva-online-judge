#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int main()
{
    int n;
    scanf("%d",&n);
    vector<string> grid;
    string in;
    for(int i=0;i<n;i++){
        cin >> in;
        grid.push_back(in);
    }
    while(cin >> in, in!="0"){
        bool found = false;
        for(int i=0;i<n&&!found;i++){
            for(int j=0;j<n&&!found;j++){
                for(auto& dir : dirs){
                    int x=i,y=j,cur=0;
                    while(cur<in.length()){
                        if(x<0||y<0||x>=n||y>=n
                        || grid[x][y] != in[cur]) break;
                        if(++cur == in.length()){
                            found = true;
                            break;
                        }
                        x+=dir[0], y+=dir[1];
                    }
                    if(found){
                        printf("%d,%d %d,%d\n",i+1,j+1,x+1,y+1);
                        break;
                    }
                }
            }
        }
        if(!found){
            printf("Not found\n");
        }
    }
}



