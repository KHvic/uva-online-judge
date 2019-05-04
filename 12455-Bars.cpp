#include <bits/stdc++.h>
using namespace std;
// can be also solved using dp in O(N*P) = 20000
// complete search is better here O(2^P) = 20^2 = 400

int main() {
    int t,n,p,v;
    cin >> t;
    while(t--){
        cin >> n >> p;
        vector<int> nums;
        for(int i=0;i<p;i++){
            cin >> v;
            nums.push_back(v);
        }
        bool found = false;
        for(int i=0;i<(1<<p) && !found;i++){
            int sum = 0;
            for(int j=0;j<p;j++)
                if(i & (1<<j)) sum += nums[j];
            if(sum == n) found = true;
        }
        cout << (found ? "YES" : "NO") << endl;
    }
}
