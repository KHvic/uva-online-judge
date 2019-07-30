#include <bits/stdc++.h>
using namespace std;

int t,k;
string str;

vector<vector<int>> memo; // state: {partitionIdx, lastCharacter}
int n; // number of partitions
vector<unordered_set<int>> partitions;

int solve(int idx,int lastCharacter){
    if(idx == n) return 0;
    else if(memo[idx][lastCharacter] != -1) return memo[idx][lastCharacter];
    int numUnique = partitions[idx].size();
    int best = INT_MAX;
    // O(26^2) = O(1), for each pair of unique character
    for(auto first=partitions[idx].begin(); first!=partitions[idx].end(); first++){
        for(auto last=partitions[idx].begin(); last!=partitions[idx].end(); last++){
            if(numUnique == 1 || first != last){
                int cost = solve(idx+1,*last) + numUnique;
                if(lastCharacter == *first) cost--;
                best = min(best, cost);
            }
        }
    }
    return memo[idx][lastCharacter] = best;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        cin >> k >> str;
        n = str.length()/k;
        memo.assign(n,vector<int>(27,-1));
        partitions.assign(n,unordered_set<int>());
        // character counting
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                int pos = i*k+j;
                partitions[i].insert(str[pos]-'a');
            }
        }
        printf("%d\n",solve(0,26));
    }
}
