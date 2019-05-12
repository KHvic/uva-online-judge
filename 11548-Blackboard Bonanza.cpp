#include <bits/stdc++.h>

using namespace std;

int compute(const string& a, const string& b){
    int best = 0;
    // imagine b shifting
    // -b.length()+1 to a.length()+b.length()-2
    int i = -b.length()+1;
    for(; i<(int)(a.length()+b.length()-1);i++){
        int cand = 0;
        for(int j=0;j<b.length();j++){
            if(i+j < 0 || i+j >=a.length()) continue;
            if(a[i+j] == b[j]) cand++;
        }
        best = max(best,cand);
    }
    return best;
}

int main()
{
    int t,n;
    string in;
    cin >> t;
    while(t--){
        int res = 0;
        cin >> n;
        vector<string> words;
        for(int i=0;i<n;i++){
            cin >> in;
            words.push_back(in);
        }
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        res = max(res,compute(words[i],words[j]));

        cout << res << endl;
    }
}
