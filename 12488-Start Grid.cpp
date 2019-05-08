#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,v;
    while(scanf("%d",&n) != EOF){
        vector<int> competitors;
        int res = 0;
        for(int i=0;i<n;i++){
            cin >> v;
            competitors.push_back(v);
        }
        for(int i=0;i<n;i++){
            cin >> v;
            auto it=competitors.begin();
            for(;*it!=v;it++){
                if(*it != -1) res++;
            }
            *it = -1;
        }
        cout << res << endl;
    }
}
