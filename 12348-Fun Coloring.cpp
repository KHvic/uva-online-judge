#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,m,v;
    string in;
    cin >> k;
    while(k--){
        cin >> n >> m;
        cin.ignore();
        vector<vector<int>> sets;
        for(int i=0;i<m;i++){
            getline(cin,in);
            istringstream iss(in);
            vector<int> s;
            while(iss >> v) s.push_back(v-1);
            sets.push_back(s);
        }
        bool found = false;
        for(int i=0;i<(1<<n) && !found;i++){
            found = true;
            for(auto& s : sets){
                int red = 0;
                for(int x : s) 
                    if(i&(1<<x)) red++;
                if(red != 1 && red != s.size()-1) {
                    found = false;
                    break;
                }
            }
        }
        cout << (found ? "Y" : "N");
    }
}
