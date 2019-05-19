#include <bits/stdc++.h>
using namespace std;
bitset<32> prime;
bitset<32> used;

void sieve(){
    prime.set();
    prime[0] = prime[1] = 0;
    for(int i=2;i<=sqrt(32);i++)
        if(prime[i]){
            for(int j=i*i;j<=32;j+=i) prime[j] = 0;
        }
}

void dfs(vector<int>& cur, int n){
    if(cur.size() == n){
        if(prime[cur.back()+cur.front()]){
            for(auto& v : cur){
                cout << v;
                if(v == cur.back()) cout << endl;
                else cout << " ";
            }
        }
        return;
    }
    for(int i=2;i<=n;i++){
        if(used[i] || !prime[i+cur.back()]) continue;
        cur.push_back(i);
        used[i] = 1;
        dfs(cur,n);
        cur.pop_back();
        used[i] = 0;
    }
}

int main()
{
    sieve();
    int n,tc=1;
    while(cin >> n){
        if(tc > 1) cout << endl;
        vector<int> res(1,1);
        used.reset();
        printf("Case %d:\n",tc++);
        dfs(res,n);
    }
}
