#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,v;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> prices;
        for(int i=0;i<n;i++){
            cin >> v;
            prices.push_back(v);
        }
        sort(prices.begin(),prices.end(),greater<int>());
        int res = 0;
        for(int i=2;i<n;i+=3) res+= prices[i];
        cout << res << endl;
    }
}
