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
using namespace std;

int main() {
    int p,c,k;
    char v;
    int cases = 1;
    while(scanf("%d %d",&p,&c),p){
        deque<int> q;
        for(int i=1;i<=min(p,1000);i++) q.push_back(i);
        cout << "Case " << cases++ << ":\n";
        for(int i=0;i<c;i++){
            cin >> v;
            if(v == 'N') {
                cout << q.front() << endl;
                q.push_back(q.front());
                q.pop_front();
            } else {
                cin >> k;
                // inefficient here, we can do better.
                // to improve time complexity, we can keep a timestamp
                // to invalidate element instead of removing them
                q.erase(remove(q.begin(),q.end(),k),q.end());
                q.push_front(k);
            }
        }
    }
}
