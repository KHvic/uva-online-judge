#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,c,s,d;
    int cases=1;
    string sub;
    scanf("%d",&t);
    while(t--){
        unordered_map<string,int> subDays;
        cin >> s;
        while(s--){
            cin >> sub >> c;
            subDays[sub] = c;
        }
        cin >> d;
        cin >> sub;
        cout << "Case " << cases++ << ": ";
        if(!subDays.count(sub) || subDays[sub] > d+5) cout << "Do your own homework!";
        else if(subDays[sub] <= d) cout << "Yesss";
        else cout << "Late";
        cout << endl;
    }
}
