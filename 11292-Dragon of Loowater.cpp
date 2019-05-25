#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,v;
    while(scanf("%d %d",&n,&m),n||m){
        vector<int> dragons;
        vector<int> knights;
        for(int i=0;i<n;i++){
            cin >> v;
            dragons.push_back(v);
        }
        for(int i=0;i<m;i++){
            cin >> v;
            knights.push_back(v);
        }
        sort(dragons.begin(),dragons.end());
        sort(knights.begin(),knights.end());
        int gold=0;int i=0;int j=0;
        while(i<n && j<m){
            while(dragons[i] > knights[j] && j<m) j++;
            if(j == m) break;
            gold += knights[j];
            i++; j++;
        }
        if(i == n) printf("%d\n",gold);
        else printf("Loowater is doomed!\n");
    }
}
