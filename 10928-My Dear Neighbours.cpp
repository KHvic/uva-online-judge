#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,p;
    string in;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d\n",&p);
        int minSize = p;
        vector<int> res;
        for(int i=1;i<=p;i++){
            getline(cin,in);
            istringstream iss(in);
            int cur = 0;
            while(iss>>in) cur++;
            if(cur<minSize){
                minSize = cur;
                res.clear();
            }
            if(cur == minSize) res.push_back(i);
        }
        for(auto& i : res) cout<<i<<(&i!=&res.back() ? " " : "\n");
    }
}
