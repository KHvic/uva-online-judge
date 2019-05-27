#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n;
    string in;
    cin >> t;
    while(t--){
        cin >> n;
        cin.ignore();
        vector<string> original, expected;
        for(int i=0;i<2*n;i++){
            getline(cin,in);
            if(i<n) original.push_back(in);
            else expected.push_back(in);
        }
        // start from b, compare
        int i=n-1,j=n-1;
        for(;i>=0;i--)
            // since they have a match, advance to next
            if(original[i] == expected[j]) j--;
        // sort the rest by putting them on top
        while(j>=0){
            cout << expected[j--] << endl;
        }
        cout << endl;
    }
}
