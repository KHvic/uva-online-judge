#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n),n!=-1){
        bool found = false;
        printf("%d coconuts, ",n);
        for(int i=sqrt(n)+1; i>1 && !found; i--){
            int remaining = n;
            int iteration = 0;
            while(iteration != i){
                remaining--;
                if(remaining%i != 0) break; // can't split
                remaining -= remaining/i;
                iteration++;
                if(iteration == i && (remaining%i == 0)){
                    found = true;
                    printf("%d people and 1 monkey\n",i);
                }
            }
        }
        if(!found) printf("no solution\n");
    }
}
