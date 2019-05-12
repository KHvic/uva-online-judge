#include <bits/stdc++.h>

using namespace std;

bool evaluate(queue<char>& q, int logic){
    char cur = q.front(); q.pop();
//    if(cur == 'p') return logic & 1;
//    else if(cur == 'q') return (logic >> 1) & 1;
//    else if(cur == 'r') return (logic >> 2) & 1;
//    else if(cur == 's') return (logic >> 3) & 1;
//    else if(cur == 't') return (logic >> 4) & 1;
    if(islower(cur)) return (logic >> (cur-'p')) & 1;

    bool left = evaluate(q,logic);
    // is an ops
    if(cur == 'N') return !left;
    bool right = evaluate(q,logic);
    if(cur == 'K') return left && right;
    else if(cur == 'A') return left || right;
    else if(cur == 'C') {
        if(left) return right;
        else return true;
    }
    else return left == right;
}

int main()
{
    string in;
    while(cin >> in, in != "0"){
        queue<char> q;
        for(auto& c : in) q.push(c);
        bool valid = true;
        for(int i=0;i<(1<<5) && valid;i++){
            queue<char> cloned = q;
            if(!evaluate(cloned,i)) valid = false;
        }
        cout << (valid ? "tautology" : "not") << endl;
    }
}
