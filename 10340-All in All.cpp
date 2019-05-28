#include <bits/stdc++.h>

using namespace std;

bool isSubseq(const string& a, const string& b){
    if(a.size() > b.size()) return false;
    int i=0;
    for(int j=0;j<b.length() && i<a.size();j++){
        if(b[j] == a[i]) i++;
    }
    return i==a.size();
}

int main()
{
    string pattern,str;
    while(cin >> pattern){
        cin >> str;
        cout << (isSubseq(pattern,str) ? "Yes" : "No") << endl;
    }
}
