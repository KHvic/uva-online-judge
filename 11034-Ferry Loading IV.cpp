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
    int n, l, m, v;
    string in;
    cin >> n;
    while(n--){
        cin >> l >> m;
        l *= 100;
        queue<int> left, right;
        int res = 0;
        bool onLeft = true;
        for(int i=0;i<m;i++){
            cin >> v >> in;
            if(in == "left") left.push(v);
            else right.push(v);
        }
        while(!left.empty() || !right.empty()){
            int capacity = l;
            res++;
            if(onLeft){
                while(!left.empty() && capacity >= left.front()){
                    capacity -= left.front(); left.pop();
                }
            } else {
                while(!right.empty() && capacity >= right.front()){
                    capacity -= right.front(); right.pop();
                }
            }
            onLeft = !onLeft;
        }
        cout << res << endl;
    }
}
