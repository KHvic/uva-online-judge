#include <bits/stdc++.h>

using namespace std;

bool match(tuple<string,int,int>& g, string& x){
    unordered_set<char> contains(x.begin()+2, x.end());
    int exact = 0;
    int colorMatch = 0;
    for(int i=0;i<4;i++){
        char cur = get<0>(g)[i];
        if(x[i+2] == cur) exact++;
        if(contains.count(cur)) colorMatch++;
    }
    colorMatch -= exact;
    return exact == get<1>(g) && colorMatch == get<2>(g);
}

int main()
{
    int t,a,b;
    string g;
    cin >> t;
    while(t--){
        vector<tuple<string,int,int>> responds;
        for(int i=0;i<2;i++){
            cin >> g >> a >> b;
            responds.push_back(make_tuple(g,a,b));
        }
        string x = "BGORVY";
        while(true){
            if(match(responds[0],x) && match(responds[1],x)){
                cout << "Possible" << endl;
                break;
            }
            if(!next_permutation(x.begin(),x.end())){
                cout << "Cheat" << endl;
                break;
            }
        }
    }
}
