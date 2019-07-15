#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    while(getline(cin,a)){
        getline(cin,b);
        int aCount[26] = {};
        int bCount[26] = {};
        for(auto& c : a){
            aCount[c-'a']++;
        }
        for(auto& c : b){
            bCount[c-'a']++;
        }
        string res = "";
        for(int i=0;i<26;i++){
            int common = min(aCount[i],bCount[i]);
            for(int j=0;j<common;j++)
                res += (char)(i+'a');
        }
        cout << res << endl;
    }
}
