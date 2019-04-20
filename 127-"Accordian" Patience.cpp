#include <bits/stdc++.h>
using namespace std;

bool isSame(string& a, string& b){
    return a[0] == b[0] || a[1] == b[1];
}
int main() {
    string next;
    while(cin >> next, next != "#"){
        vector<stack<string>> cards(52,stack<string>());
        cards[0].push(next);
        for(int i=1;i<52;i++){
            cin >> next;
            cards[i].push(next);
        }
        int cur = 0;
        while(cur<cards.size()){
            for(int i : {3,1}){
                int leftPos = cur-i;
                if(leftPos >= 0){
                    if(isSame(cards[cur].top(), cards[leftPos].top())){
                        cards[leftPos].push(cards[cur].top());
                        cards[cur].pop();
                        if(cards[cur].empty()) cards.erase(cards.begin()+cur);
                        cur = leftPos-1;
                        break;
                    }
                }
            }
            cur++;
        }
        cout << cards.size() << (cards.size() == 1 ? " pile" : " piles") << " remaining:";
        for(auto& s : cards) cout << " " << s.size();
        cout << endl;
    }
}
