#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t,v;
    int n,l;
    int cases = 1;
    cin >> t;
    while(t--){
        cin >> n >> l;
        unordered_map<int,int> order;
        for(int i=1;i<=n;i++){
            cin >> v;
            order[v] = i;
        }
        vector<int> values;
        for(int i=0;i<4;i++){
            cin >> v;
            values.push_back(v);
        }
        printf("Case %d:\n",cases++);
        while(l--){
            // check entire board
            vector<vector<int>> tic;
            int res = 0;
            bool valid = true;
            for(int i=0;i<5;i++){
                vector<int> row;
                for(int j=0;j<5;j++){
                    cin >> v;
                    row.push_back(v);
                    if(!order.count(v)) valid = false;
                }
                tic.push_back(row);
            }
            if(valid) res+=values[3];
            // check corner
            if(order.count(tic[0][0]) && order.count(tic[4][4]) &&
               order.count(tic[0][4]) && order.count(tic[4][0]))
                if(order[tic[0][0]]<=35 && order[tic[4][4]]<=35 && order[tic[4][0]]<=35 && order[tic[0][4]]<=35)
                res+=values[0];
            // check midline
            valid = true;
            for(int i=0;i<5 && valid;i++)
                if(!order.count(tic[2][i]) || order[tic[2][i]]>40)
                    valid = false;
            if(valid) res+=values[1];
            // check cross
            valid = true;
            for(int i=0;i<5 && valid;i++){
                if(!order.count(tic[i][i]) || order[tic[i][i]]>45) valid = false;
                if(!order.count(tic[4-i][i]) || order[tic[4-i][i]]>45) valid = false;
            }
            if(valid) res+=values[2];
            cout << res << endl;
        }
        if(t) cout << endl;
    }
}
