#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,d,r,v;
    while(scanf("%d %d %d",&n,&d,&r),n){
        vector<int> morning, evening;
        for(int i=0;i<2*n;i++){
            cin >> v;
            if(i<n) morning.push_back(v);
            else evening.push_back(v);
        }
        sort(morning.begin(),morning.end());
        sort(evening.begin(),evening.end(),greater<int>());
        int res = 0;
        for(int i=0;i<n;i++){
            int dist = morning[i] + evening[i];
            if(dist > d) res += (dist-d)*r;
        }
        printf("%d\n",res);
    }
}
