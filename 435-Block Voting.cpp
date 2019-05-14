#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t,p,v;
    cin >> t;
    while(t--) {
        cin >> p;
        vector<int> parties;
        int total = 0;
        for(int i=0;i<p;i++) {
            cin >> v;
            parties.push_back(v);
            total += v;
        }
        total /= 2;
        // foreach party, compute power index
        for(int i=0;i<p;i++) {
            int pIdx = 0;
            // foreach coliation combination
            for(int j=0;j<(1<<p);j++){
                // not a member of coliation
                if(!(1<<i & j)){
                    int curMembers = 0;
                    for(int k=0;k<p;k++)
                        if(1<<k & j) curMembers += parties[k];
                    if(curMembers <= total && curMembers+parties[i] > total )
                        pIdx++;
                }
            }
            printf("party %d has power index %d\n",i+1,pIdx);
        }
        cout << endl;
    }
}
