#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {5,10,20,50,100,200};
vector<int> dpChange(2001,1e8);

int main()
{
    // compute change smallest number of coin
    dpChange[0] = 0;
    for(auto& coin : coins)
        for(int i=coin;i<2001;i++)
            if(dpChange[i-coin] != 1e8)
                dpChange[i] = min(dpChange[i],dpChange[i-coin]+1);

    int amt[6] = {};
    int val,sum; double in;
    while(scanf("%d %d %d %d %d %d",amt,amt+1,amt+2,amt+3,amt+4,amt+5)
          ,(amt[0]+amt[1]+amt[2]+amt[3]+amt[4]+amt[5])!=0){
        cin >> in;
        val = round(in*100);
        sum = 0;
        for(int i=0;i<6;i++) sum += coins[i]*amt[i];
        vector<int> dpGive(sum+1,1e8);
        dpGive[0] = 0;
        // compute minimum number of ways to get x value with given coins
        // kinda similar to knapsack
        for(int i=0;i<6;i++)
            for(int j=0;j<amt[i];j++)
                for(int k=sum;k>=coins[i];k--)
                    if(dpGive[k-coins[i]] != 1e8)
                        dpGive[k] = min(dpGive[k],dpGive[k-coins[i]]+1);
        int res = 1e8;
        for(int i=val;i<=sum;i++)
            if(dpGive[i] != 1e8) res = min(res, dpGive[i]+dpChange[i-val]);
        printf("%3d\n",res);
    }
}
