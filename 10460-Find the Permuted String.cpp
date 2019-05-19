#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    // use double, 26! is too large
    double factorial[27] = {};
    factorial[0] = factorial[1] = 1;
    for(int i=2;i<27;i++) factorial[i] = factorial[i-1]*i;

    cin >> t;
    string in;
    double n;
    while(t--){
        cin >> in >> n;
        string res = "";
        n--; // start from 0 instead of 1
        double total = factorial[in.length()];
        for(int i=0;i<in.length();i++){
            total/=(i+1);
            int insertIdx = n/total;
            n = fmod(n,total);
            res.insert(res.begin()+insertIdx, in[i]);
        }
        cout << res << endl;
    }
}
