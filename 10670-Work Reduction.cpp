#include <bits/stdc++.h>
using namespace std;

int minCost(int n,int m,int a,int b){
    int res = INT_MAX;
    for(int i=0;n>=m;i++,n/=2){
        int remain = n - m;
        int cost = remain*a + i*b;
        res = min(cost,res);
    }
    return res;
}

int main() {
    int t,n,m,l,a,b,tc=1;
    string in;
    cin >> t;
    while(t--){
        cin >> n >> m >> l;
        cin.ignore();
        vector<pair<string,int>> agencies;
        for(int i=0;i<l;i++){
             getline(cin,in);
             int delimit = in.find(":");
             string name = in.substr(0,delimit);
             in = in.substr(delimit+1);
             delimit = in.find(",");
             a = stoi(in.substr(0,delimit));
             b = stoi(in.substr(delimit+1));
             agencies.push_back({name,minCost(n,m,a,b)});
        }
        auto cmp = [](const pair<string,int>& a,const pair<string,int>& b){
            if(a.second!=b.second) return a.second < b.second;
            return a.first < b.first;
        };
        sort(agencies.begin(),agencies.end(),cmp);
        printf("Case %d\n",tc++);
        for(auto& p : agencies)
            cout << p.first << " " << p.second << endl;
    }
}
