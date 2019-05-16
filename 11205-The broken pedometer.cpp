#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,p,n,v;
    cin >> t;
    while(t--){
        cin >> p >> n;
        vector<int> symbols;
        for(int i=0;i<n;i++){
            int symbol = 0;
            for(int j=0;j<p;j++){
                cin >> v;
                symbol = (symbol<<1)+v;
            }
            symbols.push_back(symbol);
        }
        int least = INT_MAX;
        for(int i=0;i<(1<<p);i++){
            unordered_set<int> represents;
            for(auto& symbol : symbols)
                represents.insert(i&symbol);
            if(represents.size() == n){
                int numBits = 0;
                v = i;
                while(v){
                    numBits++;
                    v &= (v-1);
                }
                least = min(least, numBits);
            }
        }
        cout << least << endl;
    }
}
