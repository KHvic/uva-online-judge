#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> precompute;

void compute(int d){
    int halfPow = ceil(pow(10,d/2));
    int fullPow = halfPow*halfPow;
    for(int i=0;i<fullPow;i++){
        int v = (i/halfPow) + (i%halfPow);
        if(v*v == i) precompute[d].push_back(i);
    }
}

int main() {
    int d;
    for(int i=2;i<=8;i+=2) compute(i);
    while(scanf("%d",&d) != EOF){
        for(auto& v : precompute[d])
            printf("%.*d\n",d,v);
    }
}
