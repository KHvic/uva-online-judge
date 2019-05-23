#include <bits/stdc++.h>
using namespace std;

int main()
{
    int y,n,v;
    while(cin >> y){
        cin >> n;
        vector<int> years;
        for(int i=0;i<n;i++){
            cin >> v;
            years.push_back(v);
        }
        int best=0, from=0, to=0;
        for(int i=0;i<years.size();i++){
            auto upper = upper_bound(years.begin()+i,years.end(),years[i]+y-1);
            int numPopes = upper-(years.begin()+i);
            if(numPopes > best){
                best = numPopes;
                from = years[i];
                to = *prev(upper);
            }
        }
        printf("%d %d %d\n",best,from,to);
    }
}
