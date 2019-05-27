#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,v;
    while(scanf("%d",&n) != EOF){
        vector<int> members;
        int sum = 0;
        for(int i=0;i<n;i++){
            cin >> v;
            members.push_back(v);
            sum += v;
        }
        if(sum%n == 0){
            // optimal result is to shift everyone to mean
            int avg = sum/n;
            int error = 0;
            for(auto& member : members) error += abs(avg-member);
            printf("%d\n",1+error/2);
        } else printf("-1\n");
    }
}
