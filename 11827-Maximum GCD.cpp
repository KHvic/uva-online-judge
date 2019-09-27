#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return a==0 ? b : gcd(b%a, a);
}

int main()
{
    int n,v;
    string in;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        getline(cin, in);
        istringstream iss(in);
        vector<int> vals;
        while(iss >> v) vals.push_back(v);
        int res = 0;
        for(int i=0;i<vals.size();i++)
            for(int j=i+1;j<vals.size();j++)
                res = max(res, gcd(vals[i],vals[j]));
        printf("%d\n", res);
    }
}
