#include <bits/stdc++.h>
using namespace std;

#define pa pair<int,int>

int main()
{
    string in;
    int q,p;
    priority_queue<pa,vector<pa>,greater<pa>> pq;
    unordered_map<int,int> qToP;
    while(cin >> in, in != "#"){
        cin >> q >> p;
        qToP[q] = p;
        pq.push({p,q});
    }
    int k;
    cin >> k;
    while(k--){
        pa top = pq.top(); pq.pop();
        cout << top.second << endl;
        top.first += qToP[top.second];
        pq.push(top);
    }
}
