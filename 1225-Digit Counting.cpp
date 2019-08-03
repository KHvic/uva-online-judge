#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> res(10001,vector<int>(10));
    for(int i=1;i<=10000;i++){
        res[i] = res[i-1];
        int n = i;
        while(n!=0){
            int val = n%10;
            n/=10;
            res[i][val]++;
        }
    }
    int t,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&v);
        for(auto& val : res[v]){
            printf("%d",val);
            if(&val == &res[v].back())
                printf("\n");
            else
                printf(" ");
        }
    }
}
