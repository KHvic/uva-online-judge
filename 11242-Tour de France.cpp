#include <bits/stdc++.h>
using namespace std;

int main() {
    int f,r,v;
    while(scanf("%d",&f),f){
        cin >> r;
        vector<int> teethF;
        vector<double> ratios;
        for(int i=0;i<f;i++){
            cin >> v;
            teethF.push_back(v);
        }
        for(int i=0;i<r;i++){
            cin >> v;
            for(auto& v2 : teethF){
                ratios.push_back((double)v/v2);
            }
        }
        sort(ratios.begin(), ratios.end());
        double res = DBL_MIN;
        for(int i=1;i<ratios.size();i++) res = max(ratios[i]/ratios[i-1], res);
        printf("%.2f\n",res);
    }
}
