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
using namespace std;

int main() {
    int t, v, p, k = 1;
    string in;
    while(scanf("%d",&t),t){
        unordered_map<int,queue<int>*> idToQ;
        queue<queue<int>*> teamQueue;
        while(t--){
            cin >> v;
            queue<int>* team = new queue<int>();
            for(int i=0;i<v;i++){
                cin >> p;
                idToQ[p] = team;
            }
        }
        cout << "Scenario #" << k++ << endl;
        while(cin >> in, in != "STOP"){
            if(in == "ENQUEUE"){
                cin >> p;
                idToQ[p]->push(p);
                if(idToQ[p]->size() == 1) teamQueue.push(idToQ[p]);
            } else {
                while(teamQueue.front()->empty()) teamQueue.pop();
                cout << teamQueue.front()->front() << endl;
                teamQueue.front()->pop();
            }
        }
        cout << endl;
    }
}
