#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,v;
    while(cin >> n, n){
        bool found = false;
        set<long long> nums;
        for(int i=0;i<n;i++){
           cin >> v;
           nums.insert(v);
        }
        for(auto d=nums.rbegin();d!=nums.rend() && !found;d++)
        for(auto b=nums.rbegin();b!=nums.rend() && !found;b++)
        for(auto c=next(b);c!=nums.rend() && !found;c++){
            int a = *d-*b-*c;
            if(d == b || d == c) continue;
            if(a == *d || a == *b || a == *c) continue;
            if(nums.count(a)) {
                cout << *d << endl;
                found = true;
            }
        }
        if(!found) cout << "no solution" << endl;
    }
}
