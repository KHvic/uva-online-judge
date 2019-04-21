#include <bits/stdc++.h>
using namespace std;

void backtrack(string& a,string& b, int aIdx, int bIdx, vector<char>& ops, stack<char>& sta){
    if(bIdx == b.size()){
        for(int i=0;i<ops.size();i++)
            cout << ops[i] << (i+1 != ops.size() ? " " : "");
        cout << endl;
        return;
    }
    if(aIdx < a.size()){
        ops.push_back('i');
        sta.push(a[aIdx]);
        backtrack(a,b,aIdx+1,bIdx,ops,sta);
        sta.pop();
        ops.pop_back();
    }
    // match, try to pop
    if(!sta.empty() && sta.top() == b[bIdx]){
        char temp = sta.top(); sta.pop();
        ops.push_back('o');
        backtrack(a,b,aIdx,bIdx+1,ops,sta);
        ops.pop_back();
        sta.push(temp);
    }
}

int main() {
    string a,b;
    while(cin >> a){
        cin >> b;
        cout << "[" << endl;
        vector<char> ops; stack<char> sta;
        backtrack(a,b,0,0,ops,sta);
        cout << "]" << endl;
    }
}

