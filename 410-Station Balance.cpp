#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc=1,c,s,v;
    while(scanf("%d %d",&c,&s) != EOF){
        // dummy specimens, assign 2 to each chamber
        vector<int> specimens(2*c);
        int total = 0;
        for(int i=0;i<s;i++){
            cin >> v;
            specimens[i] = v;
            total += v;
        }
        double avg = (double)total/c, imbalance = 0;
        sort(specimens.begin(),specimens.end());
        printf("Set #%d\n",tc++);
        for(int i=0;i<c;i++){
            printf(" %d:",i);
            if(specimens[i]) printf(" %d",specimens[i]);
            if(specimens[specimens.size()-1-i])
                printf(" %d",specimens[specimens.size()-1-i]);
            printf("\n");
            imbalance += abs(avg-(specimens[i]+specimens[specimens.size()-1-i]));
        }
        printf("IMBALANCE = %.5f\n",imbalance);
        printf("\n");
    }
}
