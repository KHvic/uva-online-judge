#include <bits/stdc++.h>
using namespace std;

// can be further optimized by doing character swapping at each pos

void dfs(string& in,int idx,string cur){
    if(cur.length() == in.length()){
        cout << cur << endl;
        return;
    }
    for(int i=0;i<=cur.length();i++){
        dfs(in,idx+1,cur.substr(0,i)+in[idx]+cur.substr(i));
    }
}

int main()
{
    string in;
    bool notfirst = false;
    while(cin >> in){
        if(notfirst) cout << endl;
        notfirst = true;
        dfs(in,0,"");
    }
}
