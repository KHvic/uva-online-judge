#include <bits/stdc++.h>
using namespace std;

// O(1), mathematical proof by induction of 1,2,3...
// another approach is greedy simulation
// always pick existing leftmost peg

int main()
{
    int t;
    int n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << (n+1)*(n+1)/2-1 << endl;
    }
}
