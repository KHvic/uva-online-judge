#include <bits/stdc++.h>

using namespace std;

// the optimal solution is irrelevant to alice if Bob plays optimally
// because Bob can always choose the optimal column for that row to minimize alice winnings
// answer: minimum possible combination (Bob optimal winning)

int main()
{
    int t,n,v;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> grid;
        vector<int> seq;
        for(int i=0;i<n;i++){
            vector<int> row;
            for(int j=0;j<n;j++){
                cin >> v;
                row.push_back(v);
            }
            grid.push_back(row);
            seq.push_back(i);
        }
        int best = INT_MAX;
        do{
            int sum = 0;
            // foreach row
            for(int i=0;i<n;i++)
                sum += grid[i][seq[i]]; // bob select seq[i]
            best = min(best,sum);
        } while(next_permutation(seq.begin(),seq.end()));
        cout << best << endl;
    }
}
