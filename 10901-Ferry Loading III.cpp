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
    int k;
    scanf("%d",&k);
    int n, t, m;
    int c;
    string side;
    while(k--){
        scanf("%d %d %d\n",&n,&t,&m);
        vector<int> res(m);
        queue<pair<int,int>> left;
        queue<pair<int,int>> right;
        for(int i=0;i<m;i++){
            cin >> c >> side;
            if(side == "left") left.push({c,i});
            else right.push({c,i});
        }
        bool leftNow = true;
        int time = 0;
        while(!left.empty() || !right.empty()){
            // wait for a car to arrive if needed
            int timeMinCar = min(
                    left.empty() ? INT_MAX : left.front().first,
                    right.empty() ? INT_MAX : right.front().first);
            if(time < timeMinCar){
                time = timeMinCar;
            }
            int remain = n;
            if(leftNow){
                while(remain && !left.empty() && left.front().first <= time){
                    res[left.front().second] = time+t;
                    left.pop();
                    remain--;
                }
            } else {
                while(remain && !right.empty() && right.front().first <= time){
                    res[right.front().second] = time+t;
                    right.pop();
                    remain--;
                }
            }
            time += t;
            leftNow = !leftNow;
        }
        for(auto& i : res) cout << i << endl;
        if(k) cout << endl;
    }
}
