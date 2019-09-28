#include <bits/stdc++.h>

using namespace std;

long long factorial(int k)
{
    long long res = 1;
    for(int i=2;i<=k;i++) res *= i;
    return res;
}

int main()
{
    int n;
    string in;
    scanf("%d\n",&n);
    int tc = 1;
    while(n--) {
        getline(cin, in);
        unordered_map<char,int> cntMap;
        long long res = factorial(in.size());
        for(auto c : in) cntMap[c]++;
        for(auto& p : cntMap)
            res /= factorial(p.second);
        printf("Data set %d: %lld\n", tc++, res);
    }
}
