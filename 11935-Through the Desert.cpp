#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

bool can(double cap,vector<pair<int,string>>& events,vector<int>& consume){
    int leak = 0;
    double cur = cap;
    double dist = 0;
    int j = 0;
    for(auto& p : events){
        double km = p.first-dist; dist = p.first;
        double consumption = km*(consume[j]/100.0+leak);
        cur -= consumption;

        if(cur < 0) return false;
        if(p.second == "Gas") cur = cap;
        else if(p.second == "Mechanic") leak = 0;
        else if(p.second == "Leak") leak++;
        else if(p.second == "Fuel") j++;
    }
    return true;
}

int main()
{
    int d,v,c;
    string in;
    while(cin >> d >> in >> in >> c, c){
        vector<pair<int,string>> events;
        vector<int> consume(1,c);
        while(cin >> d >> in, in != "Goal"){
            events.push_back({d,in});
            if(in == "Gas") cin >> in;
            else if(in == "Fuel"){
                cin >> in >> c;
                consume.push_back(c);
            }
        }
        events.push_back({d,in});
        double lo = 0, hi = 10000, mid = 0, ans = 0;
        while(fabs(hi-lo)>EPS){
            mid = (lo+hi)/2.0;
            if(can(mid,events,consume)){
                ans = mid; hi = mid;
            } else {
                lo = mid;
            }
        }
        printf("%.3f\n",ans);
    }
}
