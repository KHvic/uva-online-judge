#include <bits/stdc++.h>
using namespace std;

vector<double> prob = {
    12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63,
    3.93, 0.90, 0.02, 0.22, 0.90, 0.52
};
vector<char> odd = {'a', 'e', 'i', 'o', 'u'};
vector<char> even = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
double total = 0, cnt = 0;

double computeProb(const string& s){
    double res = 0;
    for(int i=1;i<=s.length();i++)
        res += i*prob[s[i-1]-'a'];
    return res;
}

void dfs(string& cur,int n,vector<int>& ccount){
    int idx = cur.length();
    if(idx == n){
        total += computeProb(cur);
        cnt++;
        return;
    }
    for(auto& c : (idx%2 ? odd : even)){
        if(ccount[c-'a']<2){
            cur += c;
            ccount[c-'a']++;
            dfs(cur,n,ccount);
            cur.pop_back();
            ccount[c-'a']--;
        }
    }
}

int main()
{
    int t;
    string in;
    unordered_map<string,double> cache;
    cin >> t;
    while(t--){
        cin >> in;
        int n = in.length();
        string key = to_string(n) + ":" + in[0];
        double val;
        if(cache.count(key)) val = cache[key];
        else {
            string cur(1,in[0]);
            vector<int> ccount(26);
            ccount[in[0]-'a']++;
            total = cnt = 0;
            dfs(cur,n,ccount);
            val = total/cnt;
            cache[key] = val;
        }
        if(computeProb(in) < val) cout << "below" << endl;
        else cout << "above or equal" << endl;
    }
}
