#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
// die format: top,down,left,right,front,back
int rollDice(int die, int dir){
    vector<bool> state;
    for(int i=0;i<6;i++) state.push_back(die&(1<<i));
    vector<bool> newState(state);
    if(dir == 0) {
        // roll forward (up)
        newState[0] = state[4];
        newState[1] = state[5];
        newState[4] = state[1];
        newState[5] = state[0];
    } else if(dir == 1) {
        // roll backward (down)
        newState[0] = state[5];
        newState[1] = state[4];
        newState[4] = state[0];
        newState[5] = state[1];
    } else if(dir == 2) {
        // roll left
        newState[0] = state[3];
        newState[1] = state[2];
        newState[3] = state[1];
        newState[2] = state[0];
    } else if(dir == 3) {
        // roll right
        newState[0] = state[2];
        newState[1] = state[3];
        newState[3] = state[0];
        newState[2] = state[1];
    }
    int res = 0;
    for(int i=0;i<6;i++)
        if(newState[i])
            res |= (1<<i);
    return res;
}

int main() {
    int n;
    string line;
    scanf("%d",&n);
    while(n--) {
        int d_x, d_y;
        int flea = 0;
        for(int i=0;i<4;i++){
            cin >> line;
            for(int j=0;j<4;j++){
                if(line[j] == 'D') {
                    d_x = i, d_y = j;
                } else if(line[j] == 'X') {
                    flea |= (1<<(i*4+j));
                }
            }
        }
        // state: d_x, d_y, flea, die_flea
        queue<vector<int>> bfs;
        set<vector<int>> visited;
        bfs.push({d_x,d_y,flea,0});
        visited.insert(bfs.front());
        bool solved = false;
        int steps = 0;
        while(!bfs.empty() && !solved){
            int len = bfs.size();
            for(int i=0;i<len;i++) {
                vector<int> cur = bfs.front(); bfs.pop();
                if(cur[2] == 0) {
                    solved = true;
                    break;
                }
                for(int i=0;i<4;i++) {
                    auto& dir = dirs[i];
                    int next_x = cur[0] + dir[0], next_y = cur[1] + dir[1];
                    if(next_x <0 || next_y < 0 || next_x >= 4 || next_y >= 4) continue;
                    int next_die = rollDice(cur[3], i);
                    bool btm_flea = next_die & (1<<1);
                    int bit_pos = next_x*4+next_y;
                    bool have_flea = cur[2] & (1<<bit_pos);
                    int next_flea = cur[2];
                    if(have_flea && btm_flea) {
                        // nothing happens
                    } else if(have_flea) {
                        next_flea ^= (1<<bit_pos);
                        next_die |= (1<<1);
                    } else if(btm_flea) {
                        next_flea |= (1<<bit_pos);
                        next_die ^= (1<<1);
                    }
                    vector<int> next = {next_x,next_y,next_flea,next_die};
                    if(visited.count(next)) continue;
                    visited.insert(next);
                    bfs.push(next);
                }
            }
            if(!solved) steps++;
        }
        if(solved) printf("%d\n", steps);
        else printf("impossible\n");
    }
}
