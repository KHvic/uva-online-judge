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
using namespace std;

int main() {
    int t, n, s, q;
    int c, v;
    scanf("%d\n",&t);
    while(t--){
        cin >> n >> s >> q;
        int time = 0;
        int cur = 0;
        int remaining = 0;
        stack<int> carrier;
        vector<queue<int>> stations(n,queue<int>());
        for(int i=0;i<n;i++){
            cin >> c;
            remaining += c;
            while(c--){
                cin >> v;
                stations[i].push(v);
            }
        }
        while(remaining){
            // upload cargo
            while(!carrier.empty()){
                // unload to A
                if(carrier.top() == cur+1) {
                    carrier.pop();
                    time++;
                    remaining--;
                }
                // attempt unload to B
                else if(stations[cur].size() >= q) break;
                else {
                    stations[cur].push(carrier.top());
                    carrier.pop();
                    time++;
                }
            }
            // load to carrier
            while(!stations[cur].empty() && carrier.size() < s){
                carrier.push(stations[cur].front());
                stations[cur].pop();
                time++;
            }
            if(remaining){
                cur = (cur+1)%n;
                time += 2;
            }
        }
        cout << time << endl;
    }
}
