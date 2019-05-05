#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,v;
    cin >> t;
    while(t--){
        cin >> n;
        int maxScore;
        int maxDiff = INT_MIN;
        cin >> maxScore;
        for(int i=1;i<n;i++){
            cin >> v;
            maxDiff = max(maxDiff, maxScore-v);
            maxScore = max(maxScore,v);
        }
        cout << maxDiff << endl;
    }
}
