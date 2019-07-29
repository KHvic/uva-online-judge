#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;

long long solve(int idx,string& str){
    if(idx==str.length()) return 0;
    if(dp[idx] != 0) return dp[idx];
    if(str[idx]=='0')
        return dp[idx] = solve(idx+1,str);
    else {
        long long best = 0;
        for(int i=idx;i<str.length();i++){
            long long val = stol(str.substr(idx,i-idx+1));
            if(val <= INT_MAX){
                best = max(best,solve(i+1,str)+val);
            } else
                break;
        }
        return dp[idx] = best;
    }
}

int main()
{
    int t;
    string in;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,in);
        dp.assign(in.length(),0);
        long long res = solve(0,in);
        printf("%lld\n",res);
    }
}



