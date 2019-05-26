#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,tc=1;
    char c;
    cin >> t;
    while(t--){
        cin >> n;
        int furthest = -1;
        int res = 0;
        for(int i=0;i<n;i++){
            cin >> c;
            if(c == '.' && furthest<i){
                furthest = i+2;// place it to next tile which cover i+2
                res++;
            }
        }
        printf("Case %d: %d\n",tc++,res);
    }
}
