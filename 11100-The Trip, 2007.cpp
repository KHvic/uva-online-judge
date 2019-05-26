#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,v,tc=0;
    while(scanf("%d",&n),n){
        if(tc++) cout << endl;
        vector<int> bags;
        for(int i=0;i<n;i++){
            cin >> v;
            bags.push_back(v);
        }
        sort(bags.begin(),bags.end());
        int maxDup = 1;
        int cur = 1;
        for(int i=1;i<bags.size();i++){
            if(bags[i] == bags[i-1]) cur++;
            else cur = 1;
            maxDup = max(cur,maxDup);
        }
        printf("%d\n",maxDup);
        for(int i=0;i<maxDup;i++){
            printf("%d",bags[i]);
            for(int j=i+maxDup;j<n;j+=maxDup)
                printf(" %d",bags[j]);
            printf("\n");
        }
    }
}
