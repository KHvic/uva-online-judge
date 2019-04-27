#include <bits/stdc++.h>
using namespace std;

string setToString(set<int>& set){
    string res = "";
    for(auto it=set.begin(); it!=set.end();it++)
        res += to_string(*it) + ":";
    return res;
}

int main() {
    int t,i,j,p,q;
    string in;
    scanf("%d\n\n",&t);
    while(t--){
        unordered_set<string> opinions;
        scanf("%d %d\n",&p,&q);
        vector<set<int>> heard(p, set<int>());
        while(getline(cin,in),!in.empty()){
            istringstream iss(in);
            iss >> i >> j;
            heard[i-1].insert(j);
        }
        for(auto& vec: heard){
            string str = setToString(vec);
            opinions.insert(str);
        }
        cout << opinions.size() << endl;
        if(t) cout << endl;
    }
}
