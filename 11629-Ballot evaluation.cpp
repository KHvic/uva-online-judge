#include <bits/stdc++.h>
using namespace std;

int main() {
    int p,g,t;
    string name, in;
    double v;
    scanf("%d %d",&p,&g);
    unordered_map<string, double> votes;

    for(int i=0;i<p;i++){
        cin >> name >> v;
        votes[name] = v*10;
    }
    for(int i=1;i<=g;i++){
        cin >> name;
        double total = votes[name];
        while(cin >> in, in == "+"){
            cin >> name;
            total += votes[name];
        }
        cin >> t;
        t *= 10;
        cout << "Guess #" << i << " was ";
        bool eval = true;
        if(in == "<") eval = total < t;
        else if(in == "<=") eval = total <= t;
        else if(in == ">") eval = total > t;
        else if(in == ">=") eval = total >= t;
        else eval = total == t;
        cout << (eval ? "correct." : "incorrect.") << endl;
    }
}
