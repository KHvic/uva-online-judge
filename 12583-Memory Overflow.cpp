#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,k;
    string names;
    cin >> t;
    int cases = 1;
    while(t--){
        cin >> n >> k >> names;
        unordered_multiset<char> remember;
        int res = 0;
        for(int i=0;i<n;i++){
            char cur = names[i];
            if(remember.count(cur)) res++;
            if(i>=k) remember.erase(remember.find(names[i-k]));
            remember.insert(cur);
        }
        printf("Case %d: %d\n", cases++, res);
    }
}
