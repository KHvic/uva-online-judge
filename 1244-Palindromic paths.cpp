#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<vector<char>> graph(n,vector<char>(n));
        vector<vector<string>> dp(n,vector<string>(n,""));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                cin >> graph[i][j];
                if(graph[i][j] != '*') dp[i][j] += graph[i][j];
            }
        // len of road, smallest subproblem first
        for(int i=2;i<n;i++){
            // starting node
            for(int j=0;j+i<n;j++){
                // pick two middle node
                for(int mid1=j+1;mid1<j+i;mid1++){
                    for(int mid2=mid1;mid2<j+i;mid2++){
                        if(graph[j][mid1] == '*' || graph[mid2][j+i] == '*') continue;
                        if(graph[j][mid1] != graph[mid2][j+i]) continue;
                        if(dp[mid1][mid2].size()+2>dp[j][j+i].size()){
                            dp[j][j+i] = graph[j][mid1] + dp[mid1][mid2] + graph[mid2][j+i];
                        } else if(dp[mid1][mid2].size()+2 == dp[j][j+i].size()){
                            string tmp = graph[j][mid1] + dp[mid1][mid2] + graph[mid2][j+i];
                            if(tmp < dp[j][j+i]) dp[j][j+i] = tmp;
                        }
                    }
                }
            }
        }
        if(dp[0][n-1].size()) cout << dp[0][n-1] << endl;
        else cout << "NO PALINDROMIC PATH" << endl;
    }
}
