#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char type,direction,a,b;
    int val;
    while(scanf("%d",&n), n!=0){
        int youngGraph[26][26] = {};
        int elderGraph[26][26] = {};
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                youngGraph[i][j] = elderGraph[i][j] = i==j ? 0 : 1e7;
        for(int i=0;i<n;i++){
            cin >> type >> direction >> a >> b >> val;
            a -= 'A';
            b -= 'A';
            if(type == 'Y'){
                youngGraph[a][b] = min(val,youngGraph[a][b]);
                if(direction == 'B'){
                    youngGraph[b][a] = min(val,youngGraph[b][a]);
                }
            } else {
                elderGraph[a][b] = min(val,elderGraph[a][b]);
                if(direction == 'B'){
                    elderGraph[b][a] = min(val,elderGraph[b][a]);
                }
            }
        }
        // floyd warshall
        for(int k=0;k<26;k++)
            for(int i=0;i<26;i++)
                for(int j=0;j<26;j++){
                    elderGraph[i][j] = min(elderGraph[i][j], elderGraph[i][k]+elderGraph[k][j]);
                    youngGraph[i][j] = min(youngGraph[i][j], youngGraph[i][k]+youngGraph[k][j]);
                }
        int best = INT_MAX;
        vector<int> meetings;
        cin >> a >> b;
        a-='A'; b-='A';
        for(int i=0;i<26;i++)
            if(youngGraph[a][i] < 1e7 && elderGraph[b][i] < 1e7){
                int cost = youngGraph[a][i]+elderGraph[b][i];
                if(cost < best){
                    best = cost;
                    meetings.clear();
                }
                if(cost == best) meetings.push_back(i+'A');
            }
        if(meetings.empty())
            printf("You will never meet.\n");
        else{
            printf("%d",best);
            for(auto& v : meetings)
                printf(" %c",v);
            printf("\n");
        }
    }
}
