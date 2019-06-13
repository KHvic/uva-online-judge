#include <bits/stdc++.h>
using namespace std;

int even,odd;
int t,r,c,w,x,y,tc=1;
int dir[2] = {};
unordered_set<string> visited;
unordered_set<string> water;

void dfs(int x,int y){
    string key = to_string(x) + ":" + to_string(y);
    if(visited.count(key)) return;
    visited.insert(key);
    int cnt = 0;
    // iterate all 8 position
    for(int t=0;t<2;t++) // for swapping dir[0] and dir[1]
    for(int i=-1;i<=1;i+=2)
    for(int j=-1;j<=1;j+=2){
        int nextX = x+dir[t^0]*i;
        int nextY = y+dir[t^1]*j;
        if(nextX<0 || nextY<0 || nextX>=r || nextY>=c) continue;
        string neighbor = to_string(nextX) + ":" + to_string(nextY);
        if(water.count(neighbor)) continue;
        cnt++;
        dfs(nextX,nextY);
    }
    // will end up double counting for the following cases
    if(dir[0]==0 || dir[1]==0 || dir[0] == dir[1]) cnt/=2;
    if(cnt%2) odd++;
    else even++;
}

int main() {
    cin >> t;
    while(t--){
        visited.clear();
        water.clear();
        even = odd = 0;
        cin >> r >> c >> dir[0] >> dir[1];
        cin >> w;
        for(int i=0;i<w;i++){
            cin >> x >> y;
            string key = to_string(x) + ":" + to_string(y);
            visited.insert(key);
            water.insert(key);
        }
        dfs(0,0);
        printf("Case %d: %d %d\n",tc++,even,odd);
    }
}
