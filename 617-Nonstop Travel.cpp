#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int cases = 1;
    double l,g,y,r;
    while(scanf("%d",&n),n != -1){
        list<int> res;
        for(int i=30;i<=60;i++) res.push_back(i);
        while(n--){
            cin >> l >> g >> y >> r;
            double total = g+y+r;
            double safe = g+y;
            auto it = res.begin();
            while(it!=res.end()){
                double timeAtLoc = l*3600/(*it);
                bool valid = fmod(timeAtLoc,total) <= safe;
                if(valid) it++;
                else it = res.erase(it);
            }
        }
        printf("Case %d:",cases++);
        if(res.empty())
            cout << " No acceptable speeds." << endl;
        else {
            for(auto it=res.begin(); it!=res.end();it++){
                auto cur = it;
                while(next(cur) != res.end() && *next(cur) == *cur+1)
                    cur++;
                if(cur == it) cout << " " << *it;
                else cout << " " << *it << "-" << *cur;
                if(&*cur != &res.back()) cout << ",";
                it = cur;
            }
            cout << endl;
        }
    }
}
