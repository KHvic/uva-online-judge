#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(scanf("%d",&n),n){
        int v;
        while(scanf("%d",&v),v){
            stack<int> station;
            queue<int> coaches;
            coaches.push(v);
            int cur = 1;
            for(int i=1;i<n;i++){
                cin >> v; coaches.push(v);
            }
            while(!coaches.empty()){
                if(station.empty() || station.top() != coaches.front()){
                    if(cur > n) break;
                    station.push(cur++);
                } else {
                    coaches.pop();
                    station.pop();
                }
            }
            cout << (coaches.empty() ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
}
