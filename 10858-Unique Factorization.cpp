#include <bits/stdc++.h>
using namespace std;

vector<vector<int>*> dfs(int n, int start){
    vector<vector<int>*> res;
    for(int i=start;i<=sqrt(n);i++)
    if(n%i==0){
        vector<vector<int>*> subRes = dfs(n/i,i);
        for(auto& vect : subRes) vect->push_back(i);
        res.insert(res.end(),subRes.begin(),subRes.end());
        res.push_back(new vector<int>{n/i,i});
    }
    return res;
}

int main()
{
    int n;
    while(cin >> n, n){
        vector<vector<int>*> res = dfs(n,2);
        cout << res.size() << endl;
        for(auto& vect : res){
            for(auto it=vect->rbegin();it!=vect->rend();it++)
                cout << *it << (&*it != &vect->front() ? " " : "");
            cout << endl;
        }
    }
}
