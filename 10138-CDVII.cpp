#include <bits/stdc++.h>
using namespace std;

struct Record{
    int month, day, hour, mins, loc;
    bool isExit;
    int getTime(){
        return mins + hour*60 + day*24*60;
    }
};
int main() {
    int t;
    string in;
    scanf("%d\n\n",&t);
    while(t--){
        int fares[24] = {};
        map<string,vector<Record>> licenseToRecord;
        for(int i=0;i<24;i++) scanf("%d",fares+i);
        cin.ignore();
        while(getline(cin,in), !in.empty()){
            istringstream iss(in);
            string plate, command;
            char ignore;
            Record r;
            iss >> plate >> r.month >> ignore >> r.day >> ignore >> r.hour >> ignore >> r.mins >> command >> r.loc;
            r.isExit = command == "exit";
            licenseToRecord[plate].push_back(r);
        }
        for(auto& p : licenseToRecord){
            sort(p.second.begin(), p.second.end(),[](Record a, Record b){
                    return a.getTime() < b.getTime();
                 });
            int totalCents = 200;
            // consecutive match then add to cost
            for(int i=0;i<p.second.size();i++)
            if(!p.second[i].isExit && i+1 < p.second.size() && p.second[i+1].isExit){
                int dist = abs(p.second[i].loc - p.second[i+1].loc);
                totalCents += dist*fares[p.second[i].hour];
                totalCents += 100;
            }
            if(totalCents != 200)
            cout << p.first << " $" << setprecision(2) << fixed << totalCents/100.0 << endl;
        }
        if(t) cout << endl;
    }
}
