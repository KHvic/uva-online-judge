#include <bits/stdc++.h>
using namespace std;
double res;
double dist,cap,speed,init;
int s;
double loc,price;

void dfs(double cur,int idx,vector<pair<double,double>>& stations,double cost,double fuel){
    if(idx == stations.size()){
        double remain = dist-cur;
        if(remain <= fuel*speed){
            res = min(res,cost);
        }
        return;
    }
    double remain = stations[idx].first-cur;
    if(remain > fuel*speed) return; // can't reach station
    fuel -= (remain/speed);
    if(fuel <= cap/2) {
        // attempt refill
        double addCost = 2+round((cap-fuel)*stations[idx].second)/100;
        dfs(stations[idx].first,idx+1,stations,cost+addCost,cap);
    }
    // don't refill
    dfs(stations[idx].first,idx+1,stations,cost,fuel);
}

int main()
{
    int tc=1;
    while(cin >> dist,dist!=-1){
        cin >> cap >> speed >> init;
        cin >> s;
        vector<pair<double,double>> stations;
        for(int i=0;i<s;i++){
            cin >> loc >> price;
            stations.push_back({loc,price});
        }
        printf("Data Set #%d\n",tc++);
        res = DBL_MAX;
        dfs(0,0,stations,init,cap);
        printf("minimum cost = $%.2f\n",res);
    }
}
