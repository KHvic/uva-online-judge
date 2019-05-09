#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<int> scores;
    scores.insert(0);
    scores.insert(50);
    for(int i=1;i<=20;i++){
        for(int j=1;j<=3;j++) scores.insert(i*j);
    }
    int n;
    while(cin >> n, n>0){
        unordered_set<string> combis;
        int permutations = 0;
        for(auto& i : scores){
            for(auto& j : scores){
                if(scores.count(n-i-j)){
                    permutations++;
                    vector<int> combi = {i,j,n-i-j};
                    sort(combi.begin(),combi.end());
                    combis.insert(to_string(combi[0]) + ":" + to_string(combi[1]) + ":" + to_string(combi[2]));
                }
            }
        }
        if(permutations == 0)
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        else
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",
                   n,combis.size(),n,permutations);
        printf("**********************************************************************\n");
    }
    printf("END OF OUTPUT\n");
}
