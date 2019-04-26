#include <bits/stdc++.h>
using namespace std;

void printQueue(priority_queue<int>& q){
    while(!q.empty()){
        cout << q.top() << endl; q.pop();
    }
}

int main() {
    int n;
    int b,sg,sb,v;
    scanf("%d",&n);
    while(n--){
        cin >> b >> sg >> sb;
        priority_queue<int> blue,green;
        while(sg--){
            cin >> v;
            green.push(v);
        }
        while(sb--){
            cin >> v;
            blue.push(v);
        }
        while(!blue.empty() && !green.empty()){
            vector<int> remainBlue, remainGreen;
            for(int i=0;i<b && !green.empty() && !blue.empty();i++){
                int gtop = green.top(),btop=blue.top();
                green.pop();blue.pop();
                if(gtop-btop>0)remainGreen.push_back(gtop-btop);
                if(btop-gtop>0)remainBlue.push_back(btop-gtop);
            }
            for(auto& i : remainBlue) blue.push(i);
            for(auto& i : remainGreen) green.push(i);
        }
        if(blue.empty() && green.empty()) cout<< "green and blue died" << endl;
        else if(blue.empty()) {
            cout << "green wins" << endl;
            printQueue(green);
        }
        else {
            cout << "blue wins" << endl;
            printQueue(blue);
        }
        if(n) cout << endl;
    }
}
