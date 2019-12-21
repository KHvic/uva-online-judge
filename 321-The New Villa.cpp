#include <bits/stdc++.h>
using namespace std;

int r,d,s,a,b,ok,tc=1;

void printResult(int room, int light, vector<vector<int>> prev) {
    if(room == 0 && light == 1) return;
    int event = prev[room][light];
    if(event >= r) {
        // switch event
        event -= r;
        printResult(room, light ^ (1<<event), prev);
        bool lightOn = (light >> event) % 2;
        if(lightOn) printf("- Switch on light in room %d.\n", event+1);
        else printf("- Switch off light in room %d.\n", event+1);
    } else {
        // room event
        printResult(event, light, prev);
        printf("- Move to room %d.\n", room+1);
    }
}

int main() {
    int room, light;
    while(scanf("%d %d %d",&r,&d,&s), (r+d+s)) {
        vector<vector<int>> graph(r);
        vector<vector<int>> switches(r);
        ok = 1<<(r-1); // only last room light
        for(int i=0;i<d;i++) {
            scanf("%d %d",&a,&b);
            a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=0;i<s;i++) {
            scanf("%d %d",&a,&b);
            a--; b--;
            switches[a].push_back(b);
        }
        // state: room, light-state
        vector<vector<bool>> visited(r,vector<bool>(1<<r,false));
        vector<vector<int>> prev(r,vector<int>(1<<r,-1));
        queue<pair<int,int>> bfs;
        bfs.push(make_pair(0,1));
        visited[0][1] = true;
        int steps = 0;
        bool solved = false;

        while(!bfs.empty() && !solved) {
            int len = bfs.size();
            for(int i=0;i<len;i++) {
                tie(room,light) = bfs.front(); bfs.pop();
                if(light == ok && room == r-1) {
                    // solved when we reach last room with all lights off
                    solved = true;
                    break;
                }
                for(auto& sw : switches[room]) {
                    int nextLight = light ^ (1<<sw);
                    if(sw == room) continue; // not allowed to turn off current room
                    if(visited[room][nextLight]) continue;
                    prev[room][nextLight] = r+sw;
                    visited[room][nextLight] = true;
                    bfs.push(make_pair(room,nextLight));
                }
                for(auto& ro : graph[room]) {
                    if(visited[ro][light]) continue;
                    bool light_on = ((light >> ro) % 2) == 1;
                    if(!light_on) continue;
                    prev[ro][light] = room;
                    visited[ro][light] = true;
                    bfs.push(make_pair(ro,light));
                }
            }
            if(!solved) steps++;
        }
        printf("Villa #%d\n",tc++);
        if(solved) {
            printf("The problem can be solved in %d steps:\n",steps);
            printResult(r-1, ok, prev);
        } else {
            printf("The problem cannot be solved.\n");
        }
        printf("\n");
    }
}
