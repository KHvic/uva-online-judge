#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return a==0 ? b : gcd(b%a, a);
}
int lcm(int a, int b){
    return a*(b/gcd(a, b));
}

int main()
{
    int val;
    while(scanf("%d",&val), val!=0){
        vector<int> divisor;
        // generate all divisor
        for(int i=1;i<=sqrt(val);i++)
            if(val%i == 0){
                divisor.push_back(i);
                if(val/i != i) divisor.push_back(val/i);
            }
        // iterate through all pairs of divisor
        int res = 0;
        for(int i=0;i<divisor.size();i++)
            for(int j=i;j<divisor.size();j++)
                if(lcm(divisor[i],divisor[j]) == val)
                    res++;
        printf("%d %d\n",val,res);
    }
}
