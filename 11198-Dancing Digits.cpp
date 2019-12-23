#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;

void sieve(){
    isPrime.assign(16, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<16;i++)
    if(isPrime[i]){
        for(int j=i*i;j<16;j+=i)
            isPrime[j] = false;
    }
}

vector<int> permute(int i, int j, vector<int>& cur){
    vector<int> res(cur.size());
    res[j] = cur[i];
    int l = 0;
    for(int k=0;k<cur.size();k++){
        if(k == i) continue;
        if(l == j) l++;
        res[l++] = cur[k];
    }
    return res;
}

bool sorted(vector<int>& cur) {
    for(int i=1;i<=cur.size();i++)
        if(abs(cur[i-1]) != i) return false;
    return true;
}

int main() {
    sieve();
    int v,tc=1;
    while(scanf("%d",&v),v) {
        vector<int> digits(1,v);
        vector<vector<int>> partners;
        for(int i=0;i<7;i++){
            scanf("%d",&v);
            digits.push_back(v);
        }
        queue<vector<int>> bfs;
        bfs.push(digits);
        set<vector<int>> visited;
        visited.insert(digits);
        bool solved = false;
        int steps = 0;
        while(!bfs.empty()){
            int len = bfs.size();
            for(int i=0;i<len;i++){
                vector<int> cur = bfs.front(); bfs.pop();
                if(sorted(cur)) {
                    solved = true;
                    break;
                }
                vector<vector<int>> permutations;
                for(int j=0;j<cur.size();j++){
                    for(int k=j+1;k<cur.size();k++){
                        if(cur[j] * cur[k] > 0) continue; // same sign
                        int sum = abs(cur[j]) + abs(cur[k]);
                        if(!isPrime[sum]) continue;
                        // move j to k
                        if(j != k-1) permutations.push_back(permute(j,k-1,cur));
                        permutations.push_back(permute(j,k,cur));
                        // move k to j
                        if(j+1 != k) permutations.push_back(permute(k,j+1,cur));
                        permutations.push_back(permute(k,j,cur));
                    }
                }
                for(auto& p : permutations) {
                    if(visited.count(p)) continue;
                    visited.insert(p);
                    bfs.push(p);
                }
            }
            if(!solved) steps++;
        }
        printf("Case %d: %d\n",tc++,(solved ? steps : -1));
    }
}
