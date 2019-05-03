#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    scanf("%d\n",&n);
    while(n--){
        getline(cin,str);
        pair<long long,long long> left = {0,1}, right = {1,0}, cur = {1,1};
        for(auto& c : str){
            if(c == 'R'){
                left = cur;
                cur = {cur.first+right.first, cur.second+right.second};
            } else {
                right = cur;
                cur = {cur.first+left.first, cur.second+left.second};
            }
        }
        cout << cur.first << "/" << cur.second << endl;
    }
}
