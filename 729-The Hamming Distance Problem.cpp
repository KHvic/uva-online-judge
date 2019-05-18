#include <bits/stdc++.h>
using namespace std;

void backtrack(string& cur, int level, int idx, int h){
    if(level == h){
        cout << cur << endl;
        return;
    } else if(idx >= cur.length()) return;
    backtrack(cur,level,idx+1,h);
    cur[idx] = '1';
    backtrack(cur,level+1,idx+1,h);
    cur[idx] = '0';
}

int main()
{
    int t;
    int n,h;
    cin >> t;
    while(t--){
        cin >> n >> h;
        string cur(n,'0');
        backtrack(cur,0,0,h);
        if(t) cout << endl;
    }
}
