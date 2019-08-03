#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    while(scanf("%d %d",&n,&k) != EOF){
        int sum = n;
        int butts = n;
        while(butts >= k){
            int newCiga = butts/k;
            butts %= k;
            sum += newCiga;
            butts += newCiga;
        }
        printf("%d\n",sum);
    }
}
