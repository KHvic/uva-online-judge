#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

int main() {
    int r,c,n,x,y;
    int cases = 1;
    int dirs[5][2] = {{0,0},{1,0},{0,1},{-1,0},{0,-1}};
    while(scanf("%d %d %d",&r,&c,&n),r){
        bitset<10000> rows;
        bitset<10000> cols;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            rows[x] = cols[y] = true;
        }
        cin >> x >> y;
        bool valid = false;
        for(auto& dir : dirs){
            int nextX = dir[0] + x;
            int nextY = dir[1] + y;
            if(nextX <0 || nextY < 0 || nextX >= r || nextY >= c) continue;
            // if rows & cols is not occupy
            if(!rows[nextX] && !cols[nextY]){
                valid = true; break;
            }
        }
        cout << "Case " << cases++ << ": ";
        if(valid) cout << "Escaped again! More 2D grid problems!" << endl;
        else cout << "Party time! Let's find a restaurant!" << endl;
    }
}

