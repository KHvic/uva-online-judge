#include <bits/stdc++.h>
using namespace std;

int cnt;

bool checkValid(string& str)
{
    for(int len=1;len<=str.length()/2;len++)
        if(str.substr(str.length()-len) ==
           str.substr(str.length()-2*len,len))
           return false;
    return true;
}

bool dfs(string& cur,int& n,int& l){
    if(cnt == n) return true;
    for(int i=0;i<l;i++){
        cur += (char)(i+'A');
        if(checkValid(cur)){
            cnt++;
            if(dfs(cur,n,l))
                return true;
        }
        cur.pop_back();
    }
    return false;
}

int main()
{
    int n,l;
    while(scanf("%d %d",&n,&l),n||l){
        string cur = ""; cnt = 0;
        dfs(cur,n,l);
        for(int i=0;i<cur.length();i++){
            cout << cur[i];
            if(i==cur.length()-1 || i%64==63) cout << endl;
            else if(i%4==3) cout << " ";
        }
        cout << cur.length() << endl;
    }
}
