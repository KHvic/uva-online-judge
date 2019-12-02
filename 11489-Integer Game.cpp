#include <bits/stdc++.h>
using namespace std;

int main() {
    // 3 scenarios after sum%3
    string in;
    int tc;
    scanf("%d",&tc);
    for(int i=1;i<=tc;i++) {
        cin >> in;
        vector<int> mod3(3);
        int sum = 0;
        for(auto& c : in) {
            int val = c-'0';
            sum += val;
            mod3[val%3]++;
        }
        bool firstWin = true;
        sum %= 3;
        if(sum==0) {
            // if mod3[0] is odd, first player win, otherwise lose
            firstWin = mod3[0]%2==1;
        } else if(sum==1) {
            // first player must remove mod3[1], afterwards second player remove mod3[0]
            if(mod3[1] > 0) {
                if(mod3[0]) {
                    mod3[0]--;
                    firstWin = mod3[0]%2==1; // same case 1
                } else firstWin = true;
            } else {
                firstWin = false;
            }
        } else {
            // first player must remove mod3[2], afterwards second player remove mod3[0]
            if(mod3[2] > 0) {
                if(mod3[0]) {
                    mod3[0]--;
                    firstWin = mod3[0]%2==1; // same case 1
                } else firstWin = true;
            } else {
                firstWin = false;
            }
        }
        printf("Case %d: %c\n", i, (firstWin ? 'S' : 'T'));
    }
}
