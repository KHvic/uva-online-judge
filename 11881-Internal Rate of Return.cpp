#include <bits/stdc++.h>
using namespace std;

double npv(vector<int>& cfs,double irr){
    double res = 0;
    for(auto it=cfs.rbegin();it!=cfs.rend();it++){
        res /= (1.0+irr);
        res += *it;
    }
    return res;
}

int main()
{
    int t,v;
    while(scanf("%d",&t),t){
        vector<int> cfs;
        for(int i=0;i<t+1;i++){
            cin >> v;
            cfs.push_back(v);
        }
        double low=-1,high=10000;
        while(high-low>1e-5){
            double mid = (low+high)/2;
            double val = npv(cfs,mid);
            // higher the irr, the lower the val
            if(val>0)low=mid; // make it smaller
            else high=mid;
        }
        printf("%.2f\n",low);
    }
}
