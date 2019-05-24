#include <bits/stdc++.h>
using namespace std;

vector<long long> build(){
    int i=0, j=0;
    vector<long long> res(1,1);
    while(res.back() <= 2147483648){
        long long smallest = min(res[i]*2,res[j]*3);
        res.push_back(smallest);
        if(res[i]*2==smallest) i++;
        if(res[j]*3==smallest) j++;
    }
    return res;
}

int main()
{
    vector<long long> nums = build();
    int m;
    while(cin >> m, m){
        cout << *lower_bound(nums.begin(),nums.end(),m) << endl;
    }
}
