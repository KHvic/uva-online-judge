#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,q;
    int v;
    string p;
    cin >> t;
    while(t--){
        cin >> q;
        vector<pair<int,pair<int,int>>> guess;
        while(q--){
            cin >> v >> p;
            guess.push_back({v,{p[0]-'0',p[2]-'0'}});
        }
        int numValid = 0;
        int res = 0;
        for(int i=0;i<=9999 && numValid<2;i++){
            bool valid = true;
            vector<int> digitCountCur(10);
            int cur = i;
            for(int k=0;k<4;k++,cur/=10){
                digitCountCur[cur%10]++;
            }
            for(int j=0;j<guess.size() && valid;j++){
                int numMatch = 0;
                int correctNum = 0;
                vector<int> digitCount(10);
                cur = i;
                int curGuess = guess[j].first;
                for(int k=0;k<4;k++,curGuess/=10,cur/=10){
                    if(curGuess%10 == cur%10) numMatch++;
                    if(++digitCount[curGuess%10]<=digitCountCur[curGuess%10])
                        correctNum++;
                }
                correctNum -= numMatch;
                if(guess[j].second.first != numMatch || guess[j].second.second != correctNum)
                    valid = false;
            }
            if(valid) {
                numValid++;
                res = i;
            }
        }
        if(numValid == 0) cout << "impossible" << endl;
        else if(numValid == 1) printf("%04d\n",res);
        else cout << "indeterminate" << endl;
    }
}
