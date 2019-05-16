#include <bits/stdc++.h>

using namespace std;

int prefixSuffixMatch(string& p, string& s){
    int best = 0;
    for(int i=0;i<s.length()&& i<p.length();i++)
        if(p.substr(p.length()-1-i) == s.substr(0,i+1))
            best = i+1;
    return best;
}

int main()
{
    int t,n;
    string in;
    int tc = 1;
    cin >> t;
    while(t--){
        cin >> n;
        vector<string> words;
        for(int i=0;i<n;i++){
            cin >> in;
            words.push_back(in);
        }
        sort(words.begin(),words.end());
        int best = INT_MAX;
        do{
            string cur = words[0];
            for(int i=1;i<words.size();i++){
                int len = prefixSuffixMatch(cur,words[i]);
                cur += words[i].substr(len);
            }
            best = min(best,(int)cur.length());
        } while(next_permutation(words.begin(),words.end()));
        printf("Case %d: %d\n",tc++,best);
    }
}
