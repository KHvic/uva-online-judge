#include <bits/stdc++.h>
using namespace std;

vector<int> cubes;

void genCubes(){
    for(int i=1;i<=21;i++){
        cubes.push_back(i*i*i);
    }
}

int main()
{
    genCubes();
    vector<long long> dp(10001);
    dp[0] = 1;
    for(auto& cube : cubes)
        for(int i=cube;i<10001;i++)
            dp[i] += dp[i-cube];
    int n;
    while(scanf("%d",&n) != EOF)
        printf("%lld\n",dp[n]);
}
