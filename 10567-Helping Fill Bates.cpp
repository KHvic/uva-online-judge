#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    string s;
    vector<vector<int>> indexes(256);
    cin >> s;
    for(int i=0;i<s.length();i++)
        indexes[s[i]].push_back(i);
    cin >> q;
    while(q--){
        cin >> s;
        int prevIndex = -1, from = 0;
        bool valid = true;
        for(int i=0;i<s.length() && valid;i++){
            // find next smallest index larger than prevIndex
            auto upper = upper_bound(indexes[s[i]].begin(),indexes[s[i]].end(),prevIndex);
            valid = upper != indexes[s[i]].end(); // no larger index
            prevIndex = *upper;
            if(i == 0) from = prevIndex;
        }
        if(valid) printf("Matched %d %d\n",from,prevIndex);
        else printf("Not matched\n");
    }
}
